#pragma once

#include "EntityList.h"
#include "Entities/Barrel.h"
#include "Entities/OilTile.h"
#include "Entities/Fire.h"
#include "Entities/Sign.h"

namespace Stages {

    class ObstacleMaker {
    private:
        EntityList* pEntityList;
    public:
        ObstacleMaker(EntityList* pEL);
        ~ObstacleMaker();
        void makeBarrel(Coordinates::Vector<float> pos);
        void makeOilTile(Coordinates::Vector<float> pos);
        void makeFire(Coordinates::Vector<float> pos);
        void makeSign(Coordinates::Vector<float> pos);
    };
}