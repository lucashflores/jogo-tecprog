#pragma once

#include "EntityList.h"
#include "Entities/Barrel.h"
#include "Entities/OilTile.h"
#include "Entities/Fire.h"
#include "Entities/Sign.h"

namespace Stages {
    class ObstacleBuilder {
    private:
        EntityList* pEntityList;
    public:
        ObstacleBuilder(EntityList* pEL);
        ~ObstacleBuilder();
        void buildBarrel(Coordinates::Vector<float> pos);
        void buildOilTile(Coordinates::Vector<float> pos);
        void buildFire(Coordinates::Vector<float> pos);
        void buildSign(Coordinates::Vector<float> pos);
    };
}