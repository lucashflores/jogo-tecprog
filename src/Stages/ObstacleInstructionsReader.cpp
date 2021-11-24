#include "Stages/ObstacleInstructionsReader.h"
using namespace Stages;

ObstacleInstructionsReader::ObstacleInstructionsReader(EntityList *pEL)  {
    if (pEL)
        entityList = pEL;
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
    Entities::Obstacle* obstacle = NULL;
    if (random <= chance) {
        if (command == "B")
            obstacle = pObstacleMaker->makeBarrel(position);
        else if (command == "F")
            obstacle = pObstacleMaker->makeFire(position);
        else if (command == "S")
            obstacle = pObstacleMaker->makeSign(position);
        else if (command == "O")
            obstacle = pObstacleMaker->makeOilTile(position);
        else
            return;
        entityList->addEntity(static_cast<Entities::Entity*>(obstacle));
        obstacle = NULL;
    }
    else
        return ;
}