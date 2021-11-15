#include "Entities/Fire.h"
using namespace Entities;

Fire::Fire(Coordinates::Vector<float> pos):
Obstacle(Id::fire, Coordinates::Vector<float>(32.f, 32.f), pos, 5) {

}

Fire::~Fire() {

}

void Fire::collide(Entity *pE, Coordinates::Vector<float> collision) {
    return;
}

