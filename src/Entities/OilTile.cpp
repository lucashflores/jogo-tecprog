#include "Entities/OilTile.h"
using namespace Entities;

OilTile::OilTile(Coordinates::Vector<float> pos): Tile(Id::oilTile, pos) {
}

OilTile::~OilTile() {}

void OilTile::collide(Entity *pE, Coordinates::Vector<float> collision) {
    return;
}