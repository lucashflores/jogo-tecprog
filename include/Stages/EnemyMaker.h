#pragma once

#include "EntityList.h"
#include "Entities/SmokerEnemy.h"
#include "Entities/DogEnemy.h"
#include "Entities/PunkBoss.h"


namespace Stages {
    class EnemyMaker {
    private:
        EntityList* pEntityList;
    public:
        EnemyMaker(EntityList *pEL);
        ~EnemyMaker();
        void makeSmokerEnemy(Coordinates::Vector<float> pos);
        void makeDogEnemy(Coordinates::Vector<float> pos);
        void makeBoss(Coordinates::Vector<float> pos);
    };
}