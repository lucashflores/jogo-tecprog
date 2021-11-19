#include "Entities/Obstacle.h"
using namespace Entities;


Obstacle::Obstacle(Id::ids i, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos, unsigned int d):
Entity(i, hit, pos), damage(d) {
    initializeSprite();
}

Obstacle::~Obstacle() {
}

void Obstacle::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(0, 0);
    Coordinates::Vector<float> size = Coordinates::Vector<float>(32.f, 32.f);

    switch(getId()){
        case Id::tile1:
            sprite = new Animation(TILE1_TEXTURE_PATH, size, imageCnt,1.f);
            break;
        case Id::tile2:
            sprite = new Animation(TILE2_TEXTURE_PATH, size, imageCnt,1.f);
            break;
        case Id::tile3:
            sprite = new Animation(TILE3_TEXTURE_PATH, size, imageCnt,1.f);
            break;
        case Id::tile4:
            sprite = new Animation(TILE4_TEXTURE_PATH, size, imageCnt,1.f);
            break;
    }

    sprite->changePosition(position);

}

void Obstacle::update(float dt) {
    return;
}




