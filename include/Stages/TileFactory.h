#pragma once

#include "EntityList.h"
#include "Entities/Tile.h"

namespace Stages {

    class TileInstructionsReader;

    class TileFactory {
    private:
        int stage;
        EntityList* pEntityList;
    public:
        TileFactory(int stg, EntityList* pEL);
        ~TileFactory();
        void readAndExecuteInstructions(std::string instructionsPath);
        void makePlatform(Coordinates::Vector<float> initialPos, unsigned int size);
        void makeRoof(Coordinates::Vector<float> initialPos, unsigned int size);
        void makeWall(Coordinates::Vector<float> initialPos, unsigned int size, bool right);
        void makeTileBackground(Coordinates::Vector<float> initialPos, Coordinates::Vector<unsigned int> size);
    };
}
