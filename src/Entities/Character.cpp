#include "Entities/Character.h"
using namespace Entities;

Character::Character(Id::ids id, unsigned char l, unsigned char d, sf::Vector2f v): life(l), damage(d), velocity(v),
Entity(id, sf::RectangleShape(sf::Vector2f (48.f, 48.f)), sf::Vector2f(0.f, 0.f)) {
    animation = NULL;
    isWalking = false;
    isFacingLeft = false;
}

Character::~Character() {
    animation = NULL;
}

void Character::setVelocity(sf::Vector2f v) {
    velocity = v;
}

sf::Vector2f Character::getVelocity() const {
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




