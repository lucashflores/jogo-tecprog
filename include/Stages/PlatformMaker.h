#pragma once

#include "Entities/Tile.h"
#include "EntityList.h"


namespace Stages {
    class PlatformMaker {
    private:
        Entities::EntityList* pEntityList;
    public:
        PlatformMaker();
        void makePlatform(Id::ids obstacleId, Coordinates::VectorFloat initialPos, unsigned int size);
        ~PlatformMaker();
    };
}
