#include "Stages/EnemyInstructionsReader.h"
using namespace Stages;

EnemyInstructionsReader::EnemyInstructionsReader(EntityList *pEL)  {
    pEnemyMaker = NULL;
    pEnemyMaker = new EnemyMaker(pEL);
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
    if (random <= chance) {
        if (command == "S")
            pEnemyMaker->makeSmokerEnemy(position);
        else if (command == "D")
            pEnemyMaker->makeDogEnemy(position);
        else if (command == "B")
            pEnemyMaker->makeBoss(position);
        else
            return;
    }
    else
        return ;
}
