#include "Stages/ObstacleInstructionsReader.h"
using namespace Stages;

ObstacleInstructionsReader::ObstacleInstructionsReader(EntityList *pEL)  {
    pObstacleMaker = NULL;
    pObstacleMaker = new ObstacleMaker(pEL);
}

ObstacleInstructionsReader::~ObstacleInstructionsReader() {
    if (pObstacleMaker)
        delete pObstacleMaker;
}

void ObstacleInstructionsReader::executeInstructions() {
    std::string command = commands[0];
    float positionX = std::stof(commands[1]);
    float positionY = std::stof(commands[2]);
    int chance = (int)((std::stof(commands[3])) * 100);
    int random = rand() % 100 + 1;
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    if (random <= chance) {
        if (command == "B")
            pObstacleMaker->makeBarrel(position);
        else if (command == "F")
            pObstacleMaker->makeFire(position);
        else if (command == "S")
            pObstacleMaker->makeSign(position);
        else if (command == "O")
            pObstacleMaker->makeOilTile(position);
        else
            return;
    }
    else
        return ;
}