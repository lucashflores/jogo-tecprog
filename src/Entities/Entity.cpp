#include "Entities/Entity.h"
#include "EntityList.h"
using namespace Entities;

Entity::Entity(Id::ids i, Coordinates::VectorFloat size, Coordinates::VectorFloat hit, Coordinates::VectorFloat pos):
Ent(i, size, pos), hitBox(hit), position(pos) {
    position = pos;
    pEntityList = EntityList::getInstance();
    pEntityList->addEntity(this);
}



Entity::~Entity() {
}


void Entity::setPosition(Coordinates::VectorFloat pos) {
    pos = sprite->changePosition(pos);
}

const Coordinates::VectorFloat Entity::getPosition() const {
    return position;
}

const Coordinates::VectorFloat Entity::getHitBox() const {
    return hitBox;
}
