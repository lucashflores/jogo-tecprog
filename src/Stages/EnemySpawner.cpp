#include "Stages/EnemySpawner.h"
using namespace Stages;

EnemySpawner::EnemySpawner(EntityList *pEL) {
    pEntityList = NULL;
    if (pEL)
        pEntityList = pEL;
}

EnemySpawner::~EnemySpawner() {
    pEntityList = NULL;
}

void EnemySpawner::spawnSmokerEnemy(Coordinates::Vector<float> pos) {
    Entities::SmokerEnemy* smoker = NULL;
    smoker = new Entities::SmokerEnemy(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(smoker));
    smoker = NULL;
}

/*
void EnemySpawner::spawnDogEnemy(Coordinates::Vector<float> pos) {
    Entities::DogEnemy* dog = NULL;
    dog = new Entities::DogEnemy(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(dog));
    dog = NULL;
}
 */