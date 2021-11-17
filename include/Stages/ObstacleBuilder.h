#pragma once

#include "EntityList.h"
#include "Entities/Box.h"
#include "Entities/OilTile.h"
#include "Entities/Fire.h"

namespace Stages {
    class ObstacleBuilder {
    private:
        EntityList* pEntityList;
    public:
        ObstacleBuilder(EntityList* pEL);
        ~ObstacleBuilder();
        void buildBox(Coordinates::Vector<float> pos);
        void buildOilTile(Coordinates::Vector<float> pos);
        void buildFire(Coordinates::Vector<float> pos);
    };
}