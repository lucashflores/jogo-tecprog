#pragma once

#include "Entities/Tile.h"
#include "EntityList.h"


namespace Stages {
    class TileMaker {
    private:
        EntityList* pEntityList;
        int stage;
    public:
        TileMaker(EntityList* pEL);
        ~TileMaker();
        void setStage(int stg);
        void makePlatform(Coordinates::Vector<float> initialPos, unsigned int size);
        void makeRoof(Coordinates::Vector<float> initialPos, unsigned int size);
        void makeWall(Coordinates::Vector<float> initialPos, unsigned int size, bool right);
        void makeTileBackground(Coordinates::Vector<float> initialPos, Coordinates::Vector<unsigned int> size);
    };
}
