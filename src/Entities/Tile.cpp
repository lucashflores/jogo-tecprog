#include "Entities/Tile.h"
using namespace Entities;


Tile::Tile(Id::ids tileId, Coordinates::Vector<float> pos): tileTextureMap(),
Obstacle(tileId,Coordinates::Vector<float>(32.f, 32.f), pos, 0) {
    createTileTextureMap();
    initializeSprite();
}

Tile::~Tile() {
}

void Tile::createTileTextureMap() {
    tileTextureMap[Id::oilTile] = OIL_TILE_TEXTURE_PATH;
    tileTextureMap[Id::tile1] = TILE1_TEXTURE_PATH;
    tileTextureMap[Id::tile2] = TILE2_TEXTURE_PATH;

}

void Tile::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(1, 1);
    Coordinates::Vector<float> size = Coordinates::Vector<float>(32.f, 32.f);
    sprite = new Animation(tileTextureMap.at(getId()), size, imageCnt, 10.f);
    sprite->changePosition(position);
}
