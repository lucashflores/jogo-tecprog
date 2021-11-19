#include "Entities/Barrel.h"
using namespace Entities;

Barrel::Barrel(Coordinates::Vector<float> pos):
Obstacle(Id::barrel, Coordinates::Vector<float>(18.f, 26.f), Coordinates::Vector<float>(18.f, 26.f), pos, 0) {}

Barrel::~Barrel() {}

void Barrel::collide(Entity *pE, Coordinates::Vector<float> collision) {
    return ;
}