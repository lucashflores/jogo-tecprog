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
    tileTextureMap[Id::tile1Bottom] = TILE1_BOTTOM;
    tileTextureMap[Id::tile1BottomCornerLeft] = TILE1_BOTTOM_CORNER_LEFT;
    tileTextureMap[Id::tile1BottomCornerRight] = TILE1_BOTTOM_CORNER_RIGHT;
    tileTextureMap[Id::tile1Top] = TILE1_TOP;
    tileTextureMap[Id::tile1TopCornerLeft] = TILE1_TOP_CORNER_LEFT;
    tileTextureMap[Id::tile1TopCornerRight] = TILE1_TOP_CORNER_RIGHT;
    tileTextureMap[Id::tile1WallLeft] = TILE1_WALL_LEFT;
    tileTextureMap[Id::tile1WallRight] = TILE1_WALL_RIGHT;
    tileTextureMap[Id::tile1Background] = TILE1_BACKGROUND;
    tileTextureMap[Id::tile2Bottom] = TILE2_BOTTOM;
    tileTextureMap[Id::tile2BottomCornerLeft] = TILE2_BOTTOM_CORNER_LEFT;
    tileTextureMap[Id::tile2BottomCornerRight] = TILE2_BOTTOM_CORNER_RIGHT;
    tileTextureMap[Id::tile2Top] = TILE2_TOP;
    tileTextureMap[Id::tile2TopCornerLeft] = TILE2_TOP_CORNER_LEFT;
    tileTextureMap[Id::tile2TopCornerRight] = TILE2_TOP_CORNER_RIGHT;
    tileTextureMap[Id::tile2WallLeft] = TILE2_WALL_LEFT;
    tileTextureMap[Id::tile2WallRight] = TILE2_WALL_RIGHT;
    tileTextureMap[Id::tile2Background] = TILE2_BACKGROUND;
}

void Tile::collide(Entity *pE, Coordinates::Vector<float> collision) {
    return;
}

void Tile::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(1, 1);
    Coordinates::Vector<float> size = Coordinates::Vector<float>(32.f, 32.f);
    sprite = new Animation(tileTextureMap.at(getId()), size, imageCnt, 10.f);
    sprite->changePosition(position);
}
