#pragma once

#include "EntityList.h"
#include "Entities/SmokerEnemy.h"
#include "Entities/DogEnemy.h"


namespace Stages {
    class EnemySpawner {
    private:
        EntityList* pEntityList;
    public:
        EnemySpawner(EntityList *pEL);

        ~EnemySpawner();

        void spawnSmokerEnemy(Coordinates::Vector<float> pos);

        void spawnDogEnemy(Coordinates::Vector<float> pos);

        void spawnBoss(Coordinates::Vector<float> pos);
    };
}