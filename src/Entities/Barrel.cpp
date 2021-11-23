#include "Entities/Barrel.h"
using namespace Entities;

Barrel::Barrel(Coordinates::Vector<float> pos):
Obstacle(Id::barrel, Coordinates::Vector<float>(18.f, 26.f), pos, 0) {
    initializeSprite();
}

Barrel::~Barrel() {}

void Barrel::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(1, 1);
    Coordinates::Vector<float> size = Coordinates::Vector<float>(18.f, 26.f);
    sprite = new Animation(BARREL_TEXTURE_PATH, size, imageCnt, 1.f);
    sprite->changePosition(position);
}