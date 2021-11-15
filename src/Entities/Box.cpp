#include "Entities/Box.h"
using namespace Entities;

Box::Box(Coordinates::Vector<float> pos): Obstacle(Id::box, Coordinates::Vector<float>(16.f, 16.f), pos, 0) {

}

Box::~Box() {}

void Box::collide(Entity *pE, Coordinates::Vector<float> collision) {
    return ;
}