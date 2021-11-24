#pragma once

#include "EntityList.h"
#include "Entities/SmokerEnemy.h"
#include "Entities/DogEnemy.h"
#include "Entities/PunkBoss.h"


namespace Stages {
    class EnemyMaker {
    public:
        EnemyMaker();
        ~EnemyMaker();
        Entities::SmokerEnemy* makeSmokerEnemy(Coordinates::Vector<float> pos);
        Entities::DogEnemy* makeDogEnemy(Coordinates::Vector<float> pos);
        Entities::PunkBoss* makeBoss(Coordinates::Vector<float> pos);
    };
}