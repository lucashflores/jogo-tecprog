#include "Entities/OilTile.h"
using namespace Entities;

OilTile::OilTile(Coordinates::Vector<float> pos): Tile(Id::oilTile, pos) {
    initializeSprite();
}

OilTile::~OilTile() {}

void OilTile::collide(Entity *pE, Coordinates::Vector<float> collision) {
    return;
}

void OilTile::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(1, 1);
    Coordinates::Vector<float> size = Coordinates::Vector<float>(32.f, 32.f);
    sprite = new Animation(OIL_TILE_TEXTURE_PATH, size, imageCnt, 1.f);
    sprite->changePosition(position);
}