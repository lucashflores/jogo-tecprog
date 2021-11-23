#include "Entities/OilTile.h"
using namespace Entities;

OilTile::OilTile(Coordinates::Vector<float> pos): Tile(Id::oilTile, pos) {
    initializeSprite();
}

OilTile::~OilTile() {}
