#include "Entities/Character.h"
using namespace Entities;

Character::Character(unsigned char l, unsigned char d, sf::Vector2f v): life(l), damage(d), velocity(v),
Entity(sf::RectangleShape(sf::Vector2f (100.f, 100.f)), sf::Vector2f(0, 0)) {
    animation = NULL;
    animationl = NULL;
}

Character::~Character() {
    animation = NULL;
    animationl = NULL;
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



