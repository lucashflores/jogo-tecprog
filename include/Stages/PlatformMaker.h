#pragma once

#include "Entities/Tile.h"
#include "EntityList.h"


namespace Stages {
    class PlatformMaker {
    private:
        EntityList* pEntityList;
    public:
        PlatformMaker(EntityList* pEL);
        void makePlatform(int stage, Coordinates::Vector<float> initialPos, unsigned int size);
        ~PlatformMaker();
    };
}
