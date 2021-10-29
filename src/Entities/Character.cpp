#include "Entities/Character.h"
using namespace Entities;

Character::Character(sf::Vector2f v): velocity(v) {
    animation = NULL;
}

Character::~Character() {
    animation = NULL;
}

