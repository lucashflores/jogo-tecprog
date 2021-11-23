#include "Stages/EnemyMaker.h"
using namespace Stages;

EnemyMaker::EnemyMaker(EntityList *pEL) {
    pEntityList = NULL;
    if (pEL)
        pEntityList = pEL;

}

EnemyMaker::~EnemyMaker() {
    pEntityList = NULL;
}


void EnemyMaker::makeSmokerEnemy(Coordinates::Vector<float> pos) {
    Entities::SmokerEnemy* smoker = NULL;
    smoker = new Entities::SmokerEnemy(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(smoker));
    smoker = NULL;
}



void EnemyMaker::makeDogEnemy(Coordinates::Vector<float> pos) {
    Entities::DogEnemy* dog = NULL;
    dog = new Entities::DogEnemy(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(dog));
    dog = NULL;
}

void EnemyMaker::makeBoss(Coordinates::Vector<float> pos) {
    Entities::PunkBoss* punk = NULL;
    punk = new Entities::PunkBoss(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(punk));
    punk = NULL;
}

