#include "Stages/StageLoader.h"
using namespace Stages;

StageLoader::StageLoader() {
    tileInstructionsReader = NULL;
    enemyMaker = NULL;
    obstacleMaker = NULL;
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
}

Stage *StageLoader::loadStage(Entities::Player* player1, Entities::Player* player2) {
    Stage* stage = NULL;
    EntityList* entityList = new EntityList();
    entityList->addEntity(player1);
    entityList->addEntity(player2);
    std::ifstream file(STAGE_SAVE_PATH);
    std::string line;
    unsigned int score;
    while (std::getline(file, line)) {
        convertStringToVector(line);
        score = std::stoi(commands[1]);
        if (std::stoi(commands[0]) == 2)
            stage = static_cast<Stage*>(loadStage2(entityList, player1, player2));
        else
            stage = static_cast<Stage*>(loadStage1(entityList, player1, player2));
        commands.clear();
    }
    file.close();
    if (stage)
        stage->setScore(score);
    return stage;
}

Stage1* StageLoader::loadStage1(EntityList *pEL, Entities::Player* player1, Entities::Player* player2) {
    Stage1* stage = new Stage1(pEL, player1, player2);
    tileInstructionsReader = new TileInstructionsReader(1, pEL);
    tileInstructionsReader->readInstructions(TILES1_INSTRUCTIONS_PATH);
    loadObstacles(pEL);
    loadEnemies(pEL, player1, player2);
    return stage;
}

Stage2* StageLoader::loadStage2(EntityList *pEL, Entities::Player* player1, Entities::Player* player2) {
    Stage2* stage = new Stage2(pEL, player1, player2);
    tileInstructionsReader = new TileInstructionsReader(2, pEL);
    tileInstructionsReader->readInstructions(TILES2_INSTRUCTIONS_PATH);
    loadObstacles(pEL);
    loadEnemies(pEL, player1, player2);
    return stage;
}

void StageLoader::loadObstacles(EntityList* pEL) {
    std::ifstream file(STAGE_SAVE_PATH);
    std::string line;
    while (std::getline(file, line)) {
        convertStringToVector(line);
        makeObstacles(pEL);
        commands.clear();
    }
    file.close();

}

void StageLoader::loadEnemies(EntityList* pEL, Entities::Player* player1, Entities::Player* player2) {
    std::ifstream file(STAGE_SAVE_PATH);
    std::string line;
    while (std::getline(file, line)) {
        convertStringToVector(line);
        makeEnemies(pEL, player1, player2);
        commands.clear();
    }
    file.close();
}

void StageLoader::loadProjectiles(EntityList *pEL) {
    std::ifstream file(STAGE_SAVE_PATH);
    std::string line;
    while (std::getline(file, line)) {
        convertStringToVector(line);
        makeProjectiles(pEL);
        commands.clear();
    }
    file.close();
}

void StageLoader::makeObstacles(EntityList* pEL) {
    obstacleMaker = new ObstacleMaker(pEL);
    std::string command = commands[0];
    float positionX = std::stof(commands[1]);
    float positionY = std::stof(commands[2]);
    int chance = (int)((std::stof(commands[3])) * 100);
    int random = rand() % 100 + 1;
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    if (random <= chance) {
        if (static_cast<Id::ids>(std::stoi(command)) == Id::barrel)
            obstacleMaker->makeBarrel(position);
        else if (static_cast<Id::ids>(std::stoi(command)) == Id::fire)
            obstacleMaker->makeFire(position);
        else if (static_cast<Id::ids>(std::stoi(command)) == Id::sign)
            obstacleMaker->makeSign(position);
        else if (static_cast<Id::ids>(std::stoi(command)) == Id::oilTile)
            obstacleMaker->makeOilTile(position);
        else
            return;
    }
    else
        return ;
}

void StageLoader::makeEnemies(EntityList* pEL, Entities::Player* player1, Entities::Player* player2){
    enemyMaker = new EnemyMaker();
    std::string command = commands[0];
    float positionX = std::stof(commands[1]);
    float positionY = std::stof(commands[2]);
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    Entities::Enemy* enemy = NULL;
    if (static_cast<Id::ids>(std::stoi(command)) == Id::smoker)
        enemy = enemyMaker->makeSmokerEnemy(position);
    else if (static_cast<Id::ids>(std::stoi(command)) == Id::dog)
        enemy = enemyMaker->makeDogEnemy(position);
    else if (static_cast<Id::ids>(std::stoi(command)) == Id::punk)
        enemy = enemyMaker->makeBoss(position);
    else
        return;

    float velocityX = std::stof(commands[3]);
    float velocityY = std::stof(commands[4]);
    int isFacingLeft = std::stoi(commands[5]);
    unsigned int life = std::stoi(commands[6]);
    enemy->setVelocity(Coordinates::Vector<float>(velocityX, velocityY));
    enemy->setPlayer(player1);
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
    projectileMaker = new ProjectileMaker();
    std::string command = commands[0];
    float positionX = std::stof(commands[1]);
    float positionY = std::stof(commands[2]);
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    if (static_cast<Id::ids>(std::stoi(command)) == Id::smoke) {
        Entities::Smoke* smoke = projectileMaker->makeSmoke(position);
        pEL->addEntity(static_cast<Entities::Entity*>(smoke));
    }
    else if (static_cast<Id::ids>(std::stoi(command)) == Id::projectile) {
        int isFacingLeft = std::stoi(commands[3]);
        Entities::Projectile* projectile = NULL;
        if (isFacingLeft)
            projectile = projectileMaker->makeProjectile(position, true);
        else
            projectile = projectileMaker->makeProjectile(position, false);
        pEL->addEntity(static_cast<Entities::Entity*>(projectile));
    }
}