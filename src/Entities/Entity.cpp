#include "Entities/Entity.h"

using namespace Entities;

Entity::Entity(Id::ids i, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos):
Ent(i), hitBox(hit), position(pos), isAlive(true) {

}

Entity::~Entity() {

}

void Entity::setPosition(Coordinates::Vector<float> pos) {
    position = pos;
}

void Entity::setDamage(unsigned int dmg) {
    if (dmg < 0)
        dmg = 0;
    damage = dmg;
}

unsigned int Entity::getDamage() const {
    return damage;
}

void Entity::eliminate() {
    isAlive = false;
}

bool Entity::getIsAlive() {
    return isAlive;
}

const Coordinates::Vector<float> Entity::getPosition() const {
    return position;
}

const Coordinates::Vector<float> Entity::getHitBox() const {
    return hitBox;
}

void Entity::saveEntityInfo(std::ofstream& out) const {


    out <<  (int)getId()           << " " <<
            getPosition().getX()   << " " <<
            getPosition().getX()   << " ";
}

void Entity::saveEntity(std::ofstream &out) const {

}