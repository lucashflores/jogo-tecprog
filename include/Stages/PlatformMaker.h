#pragma once

#include "Entities/Tile.h"
#include "EntityList.h"


namespace Stages {
    class PlatformMaker {
    private:
        EntityList* pEntityList;
    public:
        PlatformMaker(EntityList* pEL);
        void makePlatform(Id::ids obstacleId, Coordinates::Vector<float> initialPos, unsigned int size);
        ~PlatformMaker();
    };
}