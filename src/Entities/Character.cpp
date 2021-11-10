#include "Entities/Character.h"
using namespace Entities;

Character::Character(Id::ids id, unsigned char l, unsigned char d, Coordinates::VectorFloat v):
life(l), damage(d), velocity(v),
Entity(id, sf::RectangleShape(sf::Vector2f (48.f, 48.f)),
   Coordinates::VectorFloat(32.f, 16.f), Coordinates::VectorFloat(0.f, 0.f))
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

void Character::setLife(unsigned char l) {
    if (l < 0)
        l = 0;
    life = l;
}

unsigned char Character::getLife() const {
    return life;
}

void Character::setDamage(unsigned char d) {
    if (d < 0)
        d = 0;
    damage = d;
}

unsigned char Character::getDamage() const {
    return damage;
}

void Character::setIsFacingLeft(bool facingLeft) {
    isFacingLeft = facingLeft;
}

void Character::setIsWalking(bool walking) {
    isWalking = walking;
}




