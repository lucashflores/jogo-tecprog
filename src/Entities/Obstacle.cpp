#include "Entities/Obstacle.h"
using namespace Entities;


Obstacle::Obstacle(Id::ids i, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos, unsigned int d):
Entity(i, Coordinates::Vector<float>(32.f, 32.f), hit, pos), damage(d) {

}

Obstacle::~Obstacle() {
}

void Obstacle::update(float dt) {
    return;
}




