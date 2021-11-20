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
    std::string command = commands[0];
    float positionX = std::stof(commands[1]);
    float positionY = std::stof(commands[2]);
    int chance = (int)((std::stof(commands[3])) * 100);
    srand(time(NULL));
    int random = rand() % 100 + 1;
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    if (random <= chance) {
        if (command == "S")
            pEnemyFactory->makeSmokerEnemy(position);
        else if (command == "D")
            pEnemyFactory->makeDogEnemy(position);
        else if (command == "B")
            pEnemyFactory->makeBoss(position);
        else
            return;
    }
    else
        return ;
}
