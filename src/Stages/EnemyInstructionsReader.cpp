#include "Stages/EnemyInstructionsReader.h"
using namespace Stages;

EnemyInstructionsReader::EnemyInstructionsReader(EntityList *pEL, Entities::Player* p1, Entities::Player* p2, ProjectileMaker* pPM)
{
    player2 = NULL;
    if (pPM)
        projectileMaker = pPM;

    if (p1)
        player1 = p1;
    else
        player1 = NULL;

    if (p2)
        player2 = p2;
    else
        player2 = NULL;

    if (pEL)
        entityList = pEL;

    pEnemyMaker = new EnemyMaker();
}

EnemyInstructionsReader::~EnemyInstructionsReader() {
    if (pEnemyMaker)
        delete pEnemyMaker;
    projectileMaker = NULL;
    player1 = NULL;
    player2 = NULL;
    entityList = NULL;
}

void EnemyInstructionsReader::executeInstructions() {
    std::string command = commands[0];
    float positionX = std::stof(commands[1]);
    float positionY = std::stof(commands[2]);
    int chance = (int)((std::stof(commands[3])) * 100);
    int random = rand() % 100 + 1;
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    Entities::Enemy* enemy = NULL;
    Entities::SmokerEnemy* smokerEnemy = NULL;
    Entities::PunkBoss* punkBoss = NULL;
    if (random <= chance) {
        if (command == "S") {
            smokerEnemy = pEnemyMaker->makeSmokerEnemy(position);
            smokerEnemy->setProjectileMaker(projectileMaker);
            enemy = static_cast<Entities::Enemy*>(smokerEnemy);
        }
        else if (command == "D")
            enemy = static_cast<Entities::Enemy *>(pEnemyMaker->makeDogEnemy(position));
        else if (command == "B") {
            punkBoss = pEnemyMaker->makeBoss(position);
            punkBoss->setProjectileMaker(projectileMaker);
            enemy = static_cast<Entities::Enemy*>(punkBoss);
        }
    }
    if (enemy) {
        enemy->setPlayer(player1);
        if (player2)
            enemy->setPlayer(player2);
        entityList->addEntity(static_cast<Entities::Entity*>(enemy));

    }
    enemy = NULL;
    smokerEnemy = NULL;
    punkBoss = NULL;

}
