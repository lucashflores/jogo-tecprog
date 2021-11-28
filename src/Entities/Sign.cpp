#include "Entities/Sign.h"
using namespace Entities;

Sign::Sign(Coordinates::Vector<float> pos):
Obstacle(Id::sign, Coordinates::Vector<float>(32.f, 32.f), pos, 0) {
    initializeSprite();
}

Sign::~Sign() {}

void Sign::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(1, 1);
    Coordinates::Vector<float> size = Coordinates::Vector<float>(32.f, 32.f);
    sprite = new Animation(SIGN_TEXTURE_PATH, size, imageCnt, 1.f);
    sprite->changePosition(position);
}

void Sign::saveEntity(std::ofstream& out) const{
    saveEntityInfo(out);
    out << "\n";
}