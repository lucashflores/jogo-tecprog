#pragma once

#include "Entities/Tile.h"
#include "EntityList.h"


namespace Stages {
    class TileMaker {
    private:
        EntityList* pEntityList;
    public:
        TileMaker(EntityList* pEL);
        ~TileMaker();
        void makePlatform(Id::ids tileId, Coordinates::Vector<float> initialPos, unsigned int size);
        void makeWall(Id::ids tileId, Coordinates::Vector<float> initialPos, unsigned int size);
        void makeTileBackgroud(Id::ids tileId, Coordinates::Vector<float> initialPos, unsigned int sizeX, unsigned int sizeY);
    };
}
