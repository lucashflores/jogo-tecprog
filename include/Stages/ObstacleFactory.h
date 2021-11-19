#pragma once

#include "EntityList.h"
#include "Entities/Barrel.h"
#include "Entities/OilTile.h"
#include "Entities/Fire.h"
#include "Entities/Sign.h"

namespace Stages {
    class ObstacleInstructionsReader;

    class ObstacleFactory {
    private:
        EntityList* pEntityList;
    public:
        ObstacleFactory(EntityList* pEL);
        ~ObstacleFactory();
        void readAndExecuteInstructions(std::string instructionsPath);
        void makeBarrel(Coordinates::Vector<float> pos);
        void makeOilTile(Coordinates::Vector<float> pos);
        void makeFire(Coordinates::Vector<float> pos);
        void makeSign(Coordinates::Vector<float> pos);
    };
}