#include "Entities/Character.h"
using namespace Entities;

Character::Character(Id::ids i, unsigned int l, unsigned int d, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos):
life(l), velocity(Coordinates::Vector<float>(0.f, 0.f)),
Entity(i, hit, pos)
{
    setDamage(d);
    isWalking = false;
    isFacingLeft = false;
    isOnGround = false;
    isAttacking = false;
}

Character::~Character() {
}

void Character::setVelocity(Coordinates::Vector<float> v) {
    velocity = v;
}

Coordinates::Vector<float> Character::getVelocity() const {
    return velocity;
}

void Character::setLife(unsigned int l) {
    if (l < 0)
        l = 0;
    life = l;
}

int Character::getLife() const {
    return life;
}

void Character::eliminate() {
    life = 0;
    isAlive = false;
}

void Character::setIsFacingLeft(bool facingLeft) {
    isFacingLeft = facingLeft;
}

void Character::setIsWalking(bool walking) {
    isWalking = walking;
}

void Character::setIsOnGround(bool iOG) {
    isOnGround = iOG;
}

void Character::setIsAttacking(bool attacking) {
    isAttacking = attacking;
}

void Character::setVelocityCoefficient(float c) {
    if (c > 0.0f)
        velocityCoefficient = c;
}

bool Character::getIsAttacking() {
    return isAttacking;
}

