#include "Entities/Fire.h"
using namespace Entities;

Fire::Fire(Coordinates::Vector<float> pos):
Obstacle(Id::fire, Coordinates::Vector<float>(32.f, 32.f), pos, 5) {
    initializeSprite();
}

Fire::~Fire() {

}

void Fire::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(5, 1);
    Coordinates::Vector<float> size = Coordinates::Vector<float>(32.f, 32.f);
    sprite = new Animation(FIRE_TEXTURE_PATH, size, imageCnt, 1.f);
    sprite->changePosition(position);
}

void Fire::saveEntity(std::ofstream& out) const{
    saveEntityInfo(out);
}