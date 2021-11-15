#include "Entities/Entity.h"
#include "EntityList.h"
using namespace Entities;

Entity::Entity(Id::ids i, Coordinates::Vector<float> size, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos):
Ent(i, size, pos), hitBox(hit), position(pos) {
    position = pos;
    pEntityList = EntityList::getInstance();
    pEntityList->addEntity(this);
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
