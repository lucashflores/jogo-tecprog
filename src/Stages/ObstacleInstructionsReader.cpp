#include "Stages/ObstacleInstructionsReader.h"
using namespace Stages;

ObstacleInstructionsReader::ObstacleInstructionsReader(EntityList *pEL)  {
    if (pEL)
        entityList = pEL;
    pObstacleMaker = NULL;
    pObstacleMaker = new ObstacleMaker();
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
    Entities::Entity* obstacle = NULL;
    if (random <= chance) {
        if (command == "B")
            obstacle = static_cast<Entities::Entity*>(pObstacleMaker->makeBarrel(position));
        else if (command == "F")
            obstacle = static_cast<Entities::Entity*>(pObstacleMaker->makeFire(position));
        else if (command == "S")
            obstacle = static_cast<Entities::Entity*>(pObstacleMaker->makeSign(position));
        else if (command == "O")
            obstacle = static_cast<Entities::Entity*>(pObstacleMaker->makeOilTile(position));
        else
            return;
        if (obstacle)
            entityList->addEntity(obstacle);
        obstacle = NULL;
    }
    else
        return ;
}