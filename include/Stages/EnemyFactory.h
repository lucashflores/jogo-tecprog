#pragma once

#include "EntityList.h"
#include "Entities/SmokerEnemy.h"
#include "Entities/DogEnemy.h"
#include "Entities/PunkBoss.h"


namespace Stages {
    class EnemyInstructionsReader;

    class EnemyFactory {
    private:
        EntityList* pEntityList;
    public:
        EnemyFactory(EntityList *pEL);
        ~EnemyFactory();
        void readAndExecuteInstructions(std::string instructionsPath);
        void makeSmokerEnemy(Coordinates::Vector<float> pos);
        void makeDogEnemy(Coordinates::Vector<float> pos);
        void makeBoss(Coordinates::Vector<float> pos);
    };
}