#include "Stages/TileMaker.h"
using namespace Stages;

TileMaker::TileMaker(int stg, EntityList* pEL): stage(stg) {
    if (pEL)
        pEntityList = pEL;
}

TileMaker::~TileMaker() {
    pEntityList = NULL;
}

void TileMaker::makePlatform(Coordinates::Vector<float> initialPos, unsigned int size) {
    Id::ids tileId = stage == 1? Id::tile1 : Id::tile2;
    Platform* platform = NULL;
    platform = new Platform(tileId, initialPos, size, pEntityList);
    platform = NULL;
}

void TileMaker::makeWall(Coordinates::Vector<float> initialPos, unsigned int size) {
    Id::ids tileId = stage == 1? Id::tile1 : Id::tile2;
    Wall* wall = NULL;
    wall = new Wall(tileId, initialPos, size, pEntityList);
    wall = NULL;
}

