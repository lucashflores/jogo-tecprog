#include "Stages/TileInstructionsReader.h"
using namespace Stages;

TileInstructionsReader::TileInstructionsReader(int stg, EntityList* pEL) {
    pTileMaker = NULL;
    pTileMaker = new TileMaker(stg, pEL);
}

TileInstructionsReader::~TileInstructionsReader() {
    if (pTileMaker)
        delete pTileMaker;
}

void TileInstructionsReader::executeInstructions() {

    std::string command = commands[0];
    float positionX = std::stof(commands[1]);
    float positionY = std::stof(commands[2]);
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    int size = std::stoi(commands[3]);
    if (command == "P")
        pTileMaker->makePlatform(position, size);
    else if (command == "W")
        pTileMaker->makeWall(position, size);
    else
        return;

}
