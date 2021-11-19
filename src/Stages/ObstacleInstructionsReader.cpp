#include "Stages/ObstacleInstructionsReader.h"
using namespace Stages;

ObstacleInstructionsReader::ObstacleInstructionsReader(ObstacleFactory *pOF) {
    if (pOF)
        pObstacleFactory = pOF;
}

ObstacleInstructionsReader::~ObstacleInstructionsReader() {
    pObstacleFactory = NULL;
}

void ObstacleInstructionsReader::executeInstructions() {
    std::string command = commands[1];
    float positionX = std::stof(commands[2]);
    float positionY = std::stof(commands[3]);
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    if (command == "B")
        pObstacleFactory->makeBarrel(position);
    else if (command == "F")
        pObstacleFactory->makeFire(position);
    else if (command == "S")
        pObstacleFactory->makeSign(position);
    else if (command == "O")
        pObstacleFactory->makeOilTile(position);
    else
        return ;
}