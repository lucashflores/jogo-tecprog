#include "Entities/Smoke.h"
#include <iostream>

using namespace Entities;

Smoke::Smoke(Coordinates::Vector<float> pos): Entity(Id::smoke, Coordinates::Vector<float>(10.0f, 10.0f), pos),
            timer(0),
            cooldowntimer(0) {

    setDamage(1);
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

float Smoke::getCooldown(){
    return cooldowntimer;
}

void Smoke::setCooldown(float cd){
    cooldowntimer = cd;
}

float Smoke::getTimer(){
    return timer;
}

void Smoke::update(float dt) {
    sprite->animationUpdate(0, false, dt);
    timer += dt;
    if(timer>6.f) eliminate();
}

unsigned int Smoke::getDamage() {
    if((0>timer&&timer>0.01)||(1.0>timer&&timer>1.01)||(2.0>timer&&timer>2.01)||(3.0>timer&&timer>3.01))
        return damage;
    else
        return 0;
}

void Smoke::saveEntity(std::ofstream& out) const{
    saveEntityInfo(out);

}