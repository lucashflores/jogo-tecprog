#include "Stages/StageLoader.h"
using namespace Stages;

StageLoader::StageLoader() {
    tileInstructionsReader = NULL;
    enemyMaker = NULL;
    obstacleMaker = NULL;
    projectileMaker = NULL;
}

StageLoader::~StageLoader() {
    if (tileInstructionsReader)
        delete tileInstructionsReader;
    if (enemyMaker)
        delete enemyMaker;
    if (obstacleMaker)
        delete obstacleMaker;
}

void StageLoader::convertStringToVector(std::string s) {
    std::string temp = "";
    for(int i=0;i<s.length();++i){

        if(s[i]==' '){
            commands.push_back(temp);
            temp = "";
        }
        else{
            temp.push_back(s[i]);
        }

    }
    commands.push_back(temp);
}

void StageLoader::loadPlayer1(Entities::Player *player1) {
    std::ifstream player1Save(PLAYER1_SAVE_PATH);
    std::string line;
    std::getline(player1Save, line);
    convertStringToVector(line);

    float positionX = std::stof(commands[1]);
    float positionY = std::stof(commands[2]);
    float velocityX = std::stof(commands[3]);
    float velocityY = std::stof(commands[4]);
    int isFacingLeft = std::stoi(commands[5]);
    unsigned int life = std::stoi(commands[6]);


    player1->setPosition(Coordinates::Vector<float>(positionX, positionY));
    player1->setVelocity(Coordinates::Vector<float>(velocityX, velocityY));

    if (isFacingLeft)
        player1->setIsFacingLeft(true);
    else
        player1->setIsFacingLeft(false);

    player1->setLife(life);
    commands.clear();
}

void StageLoader::loadPlayer2(Entities::Player *player2) {
    std::ifstream player2Save(PLAYER2_SAVE_PATH);
    if (!(player2Save.peek() == std::ifstream::traits_type::eof())) {
        std::string line;
        std::getline(player2Save, line);
        convertStringToVector(line);

        float positionX = std::stof(commands[1]);
        float positionY = std::stof(commands[2]);
        float velocityX = std::stof(commands[3]);
        float velocityY = std::stof(commands[4]);
        int isFacingLeft = std::stoi(commands[5]);
        unsigned int life = std::stoi(commands[6]);

        player2->setPosition(Coordinates::Vector<float>(positionX, positionY));
        player2->setVelocity(Coordinates::Vector<float>(velocityX, velocityY));

        if (isFacingLeft)
            player2->setIsFacingLeft(true);
        else
            player2->setIsFacingLeft(false);

        player2->setLife(life);
    }
    commands.clear();
}

Stage *StageLoader::loadStage(Entities::Player* player1, Entities::Player* player2) {
    Stage* stage = NULL;
    EntityList* entityList = new EntityList();

    std::ifstream file(STAGE_SAVE_PATH);
    std::string line;
    std::getline(file, line);
    convertStringToVector(line);
    int twoPlayers = std::stoi(commands[2]);
    if (!twoPlayers)
        player2 = NULL;
    entityList->addEntity(player1);
    if (player2)
        entityList->addEntity(player2);
    unsigned int score;
    score = std::stoi(commands[1]);
    if (std::stoi(commands[0]) == 2) {
        commands.clear();
        stage = static_cast<Stage*>(loadStage2(entityList, player1, player2));
    }
    else {
        commands.clear();
        stage = static_cast<Stage*>(loadStage1(entityList, player1, player2));
    }

    commands.clear();

    file.close();
    if (stage)
        stage->setScore(score);
    return stage;
}

Stage1* StageLoader::loadStage1(EntityList *pEL, Entities::Player* player1, Entities::Player* player2) {
    Stage1* stage = new Stage1(pEL, player1, player2);
    tileInstructionsReader = new TileInstructionsReader(1, pEL);
    tileInstructionsReader->readInstructions(TILES1_INSTRUCTIONS_PATH);
    loadProjectiles(pEL);
    loadObstacles(pEL);
    loadEnemies(pEL, player1, player2);
    return stage;
}

Stage2* StageLoader::loadStage2(EntityList *pEL, Entities::Player* player1, Entities::Player* player2) {
    Stage2* stage = new Stage2(pEL, player1, player2);
    tileInstructionsReader = new TileInstructionsReader(2, pEL);
    tileInstructionsReader->readInstructions(TILES2_INSTRUCTIONS_PATH);
    loadProjectiles(pEL);
    loadObstacles(pEL);
    loadEnemies(pEL, player1, player2);
    return stage;
}

void StageLoader::loadObstacles(EntityList* pEL) {
    std::ifstream file(OBSTACLE_SAVE_PATH);
    std::string line;
    while (std::getline(file, line)) {
        convertStringToVector(line);
        makeObstacles(pEL);
        commands.clear();
    }
    commands.clear();
    file.close();

}

void StageLoader::loadEnemies(EntityList* pEL, Entities::Player* player1, Entities::Player* player2) {

    std::ifstream file(ENEMY_SAVE_PATH);
    std::string line;
    while (std::getline(file, line)) {
        convertStringToVector(line);
        makeEnemies(pEL, player1, player2);
        commands.clear();
    }
    commands.clear();
    file.close();
}

void StageLoader::loadProjectiles(EntityList *pEL) {
    std::ifstream file(PROJECTILE_SAVE_PATH);
    std::string line;
    while (std::getline(file, line)) {
        convertStringToVector(line);
        makeProjectiles(pEL);
        commands.clear();
    }
    commands.clear();
    file.close();
}

void StageLoader::makeObstacles(EntityList* pEL) {
    obstacleMaker = new ObstacleMaker();
    std::string command = commands[0];
    float positionX = std::stof(commands[1]);
    float positionY = std::stof(commands[2]);
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    if (static_cast<Id::ids>(std::stoi(command)) == Id::barrel)
        pEL->addEntity(obstacleMaker->makeBarrel(position));
    else if (static_cast<Id::ids>(std::stoi(command)) == Id::fire)
        pEL->addEntity(obstacleMaker->makeFire(position));
    else if (static_cast<Id::ids>(std::stoi(command)) == Id::sign)
        pEL->addEntity(obstacleMaker->makeSign(position));
    else if (static_cast<Id::ids>(std::stoi(command)) == Id::oilTile)
        pEL->addEntity(obstacleMaker->makeOilTile(position));
    else
        return;

}

void StageLoader::makeEnemies(EntityList* pEL, Entities::Player* player1, Entities::Player* player2){
    enemyMaker = new EnemyMaker();
    std::string command = commands[0];
    float positionX = std::stof(commands[1]);
    float positionY = std::stof(commands[2]);
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    Entities::SmokerEnemy* smoker = NULL;
    Entities::PunkBoss* punk = NULL;
    Entities::Enemy* enemy = NULL;
    if (static_cast<Id::ids>(std::stoi(command)) == Id::smoker) {
        smoker = enemyMaker->makeSmokerEnemy(position);
        smoker->setProjectileMaker(projectileMaker);
        enemy = static_cast<Entities::Enemy*>(smoker);
    }
    else if (static_cast<Id::ids>(std::stoi(command)) == Id::dog)
        enemy = static_cast<Entities::Enemy*>(enemyMaker->makeDogEnemy(position));
    else if (static_cast<Id::ids>(std::stoi(command)) == Id::punk) {
        punk = enemyMaker->makeBoss(position);
        //punk->setProjectileMaker();
        enemy = static_cast<Entities::Enemy*>(punk);
    }
    else
        return;

    float velocityX = std::stof(commands[3]);
    float velocityY = std::stof(commands[4]);
    int isFacingLeft = std::stoi(commands[5]);
    unsigned int life = std::stoi(commands[6]);
    enemy->setVelocity(Coordinates::Vector<float>(velocityX, velocityY));
    enemy->setPlayer(player1);
    if (player2)
        enemy->setPlayer(player2);
    if (isFacingLeft)
        enemy->setIsFacingLeft(true);
    else
        enemy->setIsFacingLeft(false);
    enemy->setLife(life);
    pEL->addEntity(static_cast<Entities::Entity*>(enemy));
    enemy = NULL;
}

void StageLoader::makeProjectiles(EntityList *pEL) {
    projectileMaker = new ProjectileMaker(pEL);
    std::string command = commands[0];
    float positionX = std::stof(commands[1]);
    float positionY = std::stof(commands[2]);
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    if (static_cast<Id::ids>(std::stoi(command)) == Id::smoke) {
        Entities::Smoke* smoke = projectileMaker->loadSmoke(position);
        pEL->addEntity(static_cast<Entities::Entity*>(smoke));
    }
    else if (static_cast<Id::ids>(std::stoi(command)) == Id::projectile) {
        int isFacingLeft = std::stoi(commands[3]);
        Entities::Projectile* projectile = NULL;
        if (isFacingLeft)
            projectile = projectileMaker->loadProjectile(position, true);
        else
            projectile = projectileMaker->loadProjectile(position, false);
        pEL->addEntity(static_cast<Entities::Entity*>(projectile));
    }
}