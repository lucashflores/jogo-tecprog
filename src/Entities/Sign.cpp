#include "Entities/Sign.h"
using namespace Entities;

Sign::Sign(Coordinates::Vector<float> pos):
Obstacle(Id::sign, Coordinates::Vector<float>(32.f,32.f), Coordinates::Vector<float>(32.f, 32.f), pos, 0) {}

Sign::~Sign() {}

void Sign::collide(Entity *pE, Coordinates::Vector<float> collision) {return ;}