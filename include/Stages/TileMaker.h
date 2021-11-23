#pragma once

#include "EntityList.h"
#include "Entities/Tile.h"

namespace Stages {

    class TileMaker {
    private:
        int stage;
        EntityList* pEntityList;
    public:
        TileMaker(int stg, EntityList* pEL);
        ~TileMaker();
        void makePlatform(Coordinates::Vector<float> initialPos, unsigned int size);
        void makeWall(Coordinates::Vector<float> initialPos, unsigned int size);
    };
}
