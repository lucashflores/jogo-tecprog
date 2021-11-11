#include "Entities/Tile.h"
using namespace Entities;


Tile::Tile(Id::ids i, Coordinates::VectorFloat pos):
Obstacle(i, Coordinates::VectorFloat(32.f, 32.f), Coordinates::VectorFloat(32.f, 32.f), pos) {
}

Tile::~Tile() {
}

void Tile::collide(Entity *pE) {
    return;
}
