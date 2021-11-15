#include "Entities/Enemy.h"
using namespace Entities;

Enemy::Enemy(Id::ids idEnemy, unsigned char life, unsigned char dmg,
             Coordinates::Vector<float> size,
             Coordinates::Vector<float> hit,
             Coordinates::Vector<float> pos):
Character(idEnemy, life, dmg, size, hit, pos) {

}

Enemy::~Enemy(){

}

