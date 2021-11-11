#include "Entities/Obstacle.h"
using namespace Entities;


Obstacle::Obstacle(Id::ids i, Coordinates::VectorFloat size, Coordinates::VectorFloat hit, Coordinates::VectorFloat pos,
                   unsigned int d): Entity(i, size, hit, pos), damage(d) {

}

Obstacle::~Obstacle() {
}


void Obstacle::collide(Entity* pE) {
    return;
}

void Obstacle::update(float dt) {
    return;
}




