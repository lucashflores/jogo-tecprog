#include "Entities/Character.h"
using namespace Entities;

Character::Character(Id::ids i, unsigned int l, unsigned int d, Coordinates::VectorFloat size, Coordinates::VectorFloat hit, Coordinates::VectorFloat pos):
life(l), damage(d), velocity(Coordinates::VectorFloat(0.f, 0.f)),
Entity(i, size, hit, pos)
{
    isWalking = false;
    isFacingLeft = false;
}

Character::~Character() {
}

void Character::setVelocity(Coordinates::VectorFloat v) {
    velocity = v;
}

Coordinates::VectorFloat Character::getVelocity() const {
    return velocity;
}

void Character::setLife(unsigned int l) {
    if (l < 0)
        l = 0;
    life = l;
}

unsigned int Character::getLife() const {
    return life;
}

void Character::setDamage(unsigned int d) {
    if (d < 0)
        d = 0;
    damage = d;
}

unsigned int Character::getDamage() const {
    return damage;
}

void Character::setIsFacingLeft(bool facingLeft) {
    isFacingLeft = facingLeft;
}

void Character::setIsWalking(bool walking) {
    isWalking = walking;
}




