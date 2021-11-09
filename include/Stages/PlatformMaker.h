#pragma once

#include "Entities/Obstacle.h"
#include "EntityList.h"


namespace Stages {
    class PlatformMaker {
    private:
        Entities::EntityList* pEntityList;

    public:
        PlatformMaker();
        void makePlatform(Coordinates::VectorFloat initialPos, unsigned int size);
        ~PlatformMaker();
    };
}
