#include "Stages/TileMaker.h"
using namespace Stages;

#include "Defines/tileafx.h"

TileMaker::TileMaker(EntityList* pEL) {
    pEntityList = NULL;
    if (pEL)
        pEntityList = pEL;

}

TileMaker::~TileMaker() {
    pEntityList = NULL;
}

void TileMaker::makePlatform(Id::ids tileId, Coordinates::Vector<float> initialPos, unsigned int size) {
    Coordinates::Vector<float> currentPos = initialPos;
    Entities::Tile* pT = NULL;
    for (int i = 0; i < size; i++) {
        pT = new Entities::Tile(tileId, currentPos);
        pEntityList->addEntity(static_cast<Entities::Entity*>(pT));
        pT = NULL;
        currentPos.setX(currentPos.getX() + 32.f);
    }
}

void TileMaker::makeWall(Id::ids tileId, Coordinates::Vector<float> initialPos, unsigned int size) {
    Coordinates::Vector<float> currentPos = initialPos;
    Entities::Tile* pT = NULL;
    for (int i = 0; i < size; i++) {
        pT = new Entities::Tile(tileId, currentPos);
        pEntityList->addEntity(static_cast<Entities::Entity*>(pT));
        pT = NULL;
        currentPos.setY(currentPos.getY() + 32.f);
    }
}

void TileMaker::makeTileBackgroud(Id::ids tileId, Coordinates::Vector<float> initialPos,
                                  unsigned int sizeX, unsigned int sizeY) {
    int stage = tileId == Id::tile1 ? 1 : 2;
    Coordinates::Vector<float> currentPos = initialPos;
    Entities::Tile* pT = NULL;
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            pT = new Entities::Tile(tileId, currentPos);
            pEntityList->addEntity(static_cast<Entities::Entity*>(pT));
            pT = NULL;
            currentPos.setX(currentPos.getX() + 32.f);
        }
        currentPos.setX(initialPos.getX());
        currentPos.setY(currentPos.getY() + 32.f);
        pT = NULL;
    }

}