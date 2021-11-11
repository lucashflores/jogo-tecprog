#include "Entities/Enemy.h"
using namespace Entities;

Enemy::Enemy(Id::ids idEnemy, unsigned char life, unsigned char dmg,
             Coordinates::VectorFloat size,
             Coordinates::VectorFloat hit,
             Coordinates::VectorFloat pos):
Character(idEnemy, life, dmg, size, hit, pos) {

}

Enemy::~Enemy(){

}

