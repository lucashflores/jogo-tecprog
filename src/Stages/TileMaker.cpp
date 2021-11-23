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
    Coordinates::Vector<float> currentPos = initialPos;
    Entities::Tile* pT = NULL;
    Id::ids tileId = stage == 1? Id::tile1 : Id::tile2;
    for (int i = 0; i < size; i++) {
        pT = new Entities::Tile(tileId, currentPos);
        pEntityList->addEntity(static_cast<Entities::Entity*>(pT));
        pT = NULL;
        currentPos.setX(currentPos.getX() + 32.f);
    }
}

void TileMaker::makeWall(Coordinates::Vector<float> initialPos, unsigned int size) {
    Coordinates::Vector<float> currentPos = initialPos;
    Entities::Tile* pT = NULL;
    Id::ids tileId = stage == 1? Id::tile1 : Id::tile2;
    for (int i = 0; i < size; i++) {
        pT = new Entities::Tile(tileId, currentPos);
        pEntityList->addEntity(static_cast<Entities::Entity*>(pT));
        pT = NULL;
        currentPos.setY(currentPos.getY() + 32.f);
    }
}

