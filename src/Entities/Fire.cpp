#include "Entities/Fire.h"
using namespace Entities;

Fire::Fire(Coordinates::Vector<float> pos):
Obstacle(Id::fire, Coordinates::Vector<float>(32.f, 32.f), pos, 5), timer(0) {
    initializeSprite();
}

Fire::~Fire() {

}

void Fire::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(5, 1);
    Coordinates::Vector<float> size = Coordinates::Vector<float>(32.f, 32.f);
    sprite = new Animation(FIRE_TEXTURE_PATH, size, imageCnt, 0.2f);
    sprite->changePosition(position);
}

void Fire::setTimer(float time){
    timer = time;
}

float Fire::getTimer(){
    return timer;
}

void Fire::update(float dt) {
    sprite->animationUpdate(0, false ,dt);
    timer += dt;
}

void Fire::saveEntity(std::ofstream& out) const{
    saveEntityInfo(out);
}