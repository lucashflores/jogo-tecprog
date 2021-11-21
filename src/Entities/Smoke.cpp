#include "Entities/Smoke.h"
#include <iostream>

using namespace Entities;

Smoke::Smoke(Coordinates::Vector<float> pos): Entity(Id::smoke, Coordinates::Vector<float>(10.0f, 10.0f), pos),
            timer(0) {

    setDamage(2);
    initializeSprite();
}
Smoke::~Smoke() {

}

void Smoke::initializeSprite(){
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(1, 1);
    Coordinates::Vector<float> size = Coordinates::Vector<float>(30.f, 30.f);
    sprite = new Animation(SMOKE_TEXTURE_PATH, size, imageCnt,1.f);
    sprite->changePosition(position);
}

void Smoke::update(float dt) {
    sprite->animationUpdate(0, false, dt);
    timer += dt;
    if(timer>3.f){ eliminate(); std::cout << "Tchau fumasa" << std::endl;}
}