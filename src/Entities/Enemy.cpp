#include "Entities/Enemy.h"
using namespace Entities;

Enemy::Enemy(Id::ids IdEnemy, unsigned char life, unsigned char dmg, sf::Vector2f velocity) : Character(IdEnemy, life, dmg, velocity) {

}

Enemy::~Enemy(){

}

