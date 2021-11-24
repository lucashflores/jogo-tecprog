#pragma once

#include "EntityList.h"
#include "Entities/Barrel.h"
#include "Entities/OilTile.h"
#include "Entities/Fire.h"
#include "Entities/Sign.h"

namespace Stages {

    class ObstacleMaker {
    public:
        ObstacleMaker(EntityList* pEL);
        ~ObstacleMaker();
        Entities::Barrel* makeBarrel(Coordinates::Vector<float> pos);
        Entities::OilTile* makeOilTile(Coordinates::Vector<float> pos);
        Entities::Fire* makeFire(Coordinates::Vector<float> pos);
        Entities::Sign* makeSign(Coordinates::Vector<float> pos);
    };
}