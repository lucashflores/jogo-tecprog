#include "Entities/Entity.h"
#include "EntityList.h"
using namespace Entities;

Entity::Entity(Id::ids i, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos):
Ent(i), hitBox(hit), position(pos) {
    position = pos;
}



Entity::~Entity() {
}


void Entity::setPosition(Coordinates::Vector<float> pos) {
    position = pos;
}


const Coordinates::Vector<float> Entity::getPosition() const {
    return position;
}

const Coordinates::Vector<float> Entity::getHitBox() const {
    return hitBox;
}
