#include "Concurrent/BossThread.h"

const float* Concurrent::BossThread::pDt = NULL;
float Concurrent::BossThread::last_pDt(-1);

void Concurrent::BossThread::run() {
    std::cout << "Boss running" << std::endl;

    _canRun = true;

    while(_canRun){
        lock();
        //printf("lets update\t");
            update(0.00000167f);
        //printf("updated\n");
        unlock();
    }
    std::cout << "Morto!" << std::endl;
}

Concurrent::BossThread::BossThread(Coordinates::Vector<float> pos) : PunkBoss(pos) {

}

Concurrent::BossThread::~BossThread() {

}

void Concurrent::BossThread::stop() {
    _canRun = false;
}

void Concurrent::BossThread::pause(const bool pause) {
    _isAlive = !pause;
}

const bool Concurrent::BossThread::isAlive() const {
    return _canRun;
}

void Concurrent::BossThread::set_pDt(const float &dt) {
    BossThread::pDt = &dt;
}