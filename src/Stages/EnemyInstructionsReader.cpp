#include "Stages/EnemyInstructionsReader.h"
using namespace Stages;

EnemyInstructionsReader::EnemyInstructionsReader(EnemyFactory *pEF) {
    if (pEF)
        pEnemyFactory = pEF;
}

EnemyInstructionsReader::~EnemyInstructionsReader() {
    pEnemyFactory = NULL;
}

void EnemyInstructionsReader::executeInstructions() {
    std::string command = commands[1];
    float positionX = std::stof(commands[2]);
    float positionY = std::stof(commands[3]);
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    if (command == "S")
        pEnemyFactory->makeSmokerEnemy(position);
    else if (command == "D")
        return ;
        //pEnemyFactory->makeDogEnemy(position);
    else if (command == "B")
        return ;
        //pEnemyFactory->makeBoss(position);
    else
        return ;
}
