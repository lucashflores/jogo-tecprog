#include "Stages/EnemyMaker.h"
using namespace Stages;
#include "Concurrent/BossThread.h"

EnemyMaker::EnemyMaker() {
}

EnemyMaker::~EnemyMaker() {
}


Entities::SmokerEnemy* EnemyMaker::makeSmokerEnemy(Coordinates::Vector<float> pos) {
    Entities::SmokerEnemy* smoker = NULL;
    smoker = new Entities::SmokerEnemy(pos);
    return smoker;
}

Entities::DogEnemy* EnemyMaker::makeDogEnemy(Coordinates::Vector<float> pos) {
    Entities::DogEnemy* dog = NULL;
    dog = new Entities::DogEnemy(pos);
    return dog;
}

Entities::PunkBoss* EnemyMaker::makeBoss(Coordinates::Vector<float> pos) {

    Concurrent::BossThread* punkThread;
    punkThread = new Concurrent::BossThread(pos);
    Concurrent::BossThread::lock();

    punkThread->start();
    //punkThread->join();

    return static_cast<Entities::PunkBoss*>(punkThread);

    /*Entities::PunkBoss* punk = NULL;
    punk = new Entities::PunkBoss(pos);
    return punk;*/
}

