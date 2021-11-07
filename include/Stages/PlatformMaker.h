#pragma once

#include "Entities/Obstacle.h"
#include "Entities/EntityList.h"

namespace Stages {
    class PlatformMaker {
    private:
        Entities::EntityList* pEntityList;

    public:
        PlatformMaker();
        void makePlatform(sf::Vector2f initialPos, unsigned int size);
        ~PlatformMaker();
    };
}
