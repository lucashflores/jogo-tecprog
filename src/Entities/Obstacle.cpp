#include "Entities/Obstacle.h"
using namespace Entities;


Obstacle::Obstacle(Id::ids i, Coordinates::Vector<float> size, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos, unsigned int d):
Entity(i, size, hit, pos), damage(d) {

}

Obstacle::~Obstacle() {
}

void Obstacle::update(float dt) {
    return;
}




