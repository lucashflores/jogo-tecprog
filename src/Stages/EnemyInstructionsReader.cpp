#include "Stages/EnemyInstructionsReader.h"
using namespace Stages;

EnemyInstructionsReader::EnemyInstructionsReader(EntityList *pEL, Entities::Player* player1, Entities::Player* player2)
{
    if (pEL)
        entityList = pEL;
    pEnemyMaker = NULL;
    pEnemyMaker = new EnemyMaker();
}

EnemyInstructionsReader::~EnemyInstructionsReader() {
    if (pEnemyMaker)
        delete pEnemyMaker;
}

void EnemyInstructionsReader::executeInstructions() {
    std::string command = commands[0];
    float positionX = std::stof(commands[1]);
    float positionY = std::stof(commands[2]);
    int chance = (int)((std::stof(commands[3])) * 100);
    int random = rand() % 100 + 1;
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    Entities::Enemy* enemy = NULL;
    if (random <= chance) {
        if (command == "S")
            enemy = pEnemyMaker->makeSmokerEnemy(position);
        else if (command == "D")
            enemy = pEnemyMaker->makeDogEnemy(position);
        else if (command == "B")
            enemy = pEnemyMaker->makeBoss(position);
        else
            return ;
        entityList->addEntity(static_cast<Entities::Entity*>(enemy));
        enemy->setPlayer(player1);
        enemy->setPlayer(player2);
        enemy = NULL;
    }
    else
        return ;
}
