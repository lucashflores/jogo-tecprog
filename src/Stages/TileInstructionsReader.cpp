#include "Stages/TileInstructionsReader.h"
using namespace Stages;

TileInstructionsReader::TileInstructionsReader(TileFactory *pTF) {
    if (pTF)
        pTileFactory = pTF;
}

TileInstructionsReader::~TileInstructionsReader() {
    pTileFactory = NULL;
}

void TileInstructionsReader::executeInstructions() {
    std::string command = commands[1];
    float positionX = std::stof(commands[2]);
    float positionY = std::stof(commands[3]);
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    if (command == "G" || command == "R" || command == "W") {
        int size = std::stoi(commands[4]);
        if (command == "G")
            pTileFactory->makePlatform(position, size);
        else if (command == "R")
            pTileFactory->makeRoof(position, size);
        else if (command == "W") {
            bool right = false;
            if (std::stoi(commands[5]))
                right = true;
            pTileFactory->makeWall(position, size, right);
        }
    }
    else if (command == "B") {
        float sizeX = std::stod(commands[4]);
        float sizeY = std::stod(commands[5]);
        Coordinates::Vector<unsigned int> size = Coordinates::Vector<unsigned int>(sizeX, sizeY);
        pTileFactory->makeTileBackground(position, size);
    }
}