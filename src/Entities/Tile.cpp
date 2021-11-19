#include "Entities/Tile.h"
using namespace Entities;


Tile::Tile(Id::ids tileId, Coordinates::Vector<float> pos):
Obstacle(tileId, Coordinates::Vector<float>(32.f, 32.f), Coordinates::Vector<float>(32.f, 32.f), pos, 0) {
}

Tile::~Tile() {
}

void Tile::collide(Entity *pE, Coordinates::Vector<float> collision) {
    return;
}
