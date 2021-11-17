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

void TileMaker::setStage(int stg) {
    stage = stg;
    if (stage != 1 && stage != 2)
        stage = 1;
}

void TileMaker::makePlatform(Coordinates::Vector<float> initialPos, unsigned int size) {
    Coordinates::Vector<float> currentPos = initialPos;
    Entities::Tile* pT = NULL;
    Id::ids tileId = stage == 1? Id::tile1Bottom : Id::tile2Bottom;
    for (int i = 0; i < size; i++) {
        pT = new Entities::Tile(tileId, currentPos);
        pEntityList->addEntity(static_cast<Entities::Entity*>(pT));
        pT = NULL;
        currentPos.setX(currentPos.getX() + 32.f);
    }
}

void TileMaker::makeRoof(Coordinates::Vector<float> initialPos, unsigned int size) {
    Coordinates::Vector<float> currentPos = initialPos;
    Entities::Tile* pT = NULL;
    Id::ids tileId = stage == 1? Id::tile1Top : Id::tile2Top;
    for (int i = 0; i < size; i++) {
        pT = new Entities::Tile(tileId, currentPos);
        pEntityList->addEntity(static_cast<Entities::Entity*>(pT));
        pT = NULL;
        currentPos.setX(currentPos.getX() + 32.f);
    }
}

void TileMaker::makeWall(Coordinates::Vector<float> initialPos, unsigned int size, bool right) {
    Coordinates::Vector<float> currentPos = initialPos;
    Entities::Tile* pT = NULL;
    if (right) {
        Id::ids tileCornerTopId = stage == 1? Id::tile1TopCornerRight : Id::tile2TopCornerRight;
        Id::ids tileId = stage == 1? Id::tile1WallRight : Id::tile2WallRight;
        Id::ids tileCornerBottomId = stage == 1? Id::tile1BottomCornerRight : Id::tile2BottomCornerRight;
        pT = new Entities::Tile(tileCornerTopId, currentPos);
        pEntityList->addEntity(static_cast<Entities::Entity *>(pT));
        pT = NULL;
        for (int i = 1; i < size - 1; i++) {
            pT = new Entities::Tile(tileId, currentPos);
            pEntityList->addEntity(static_cast<Entities::Entity *>(pT));
            pT = NULL;
            currentPos.setY(currentPos.getY() + 32.f);
        }
        pT = new Entities::Tile(tileCornerBottomId, currentPos);
        pEntityList->addEntity(static_cast<Entities::Entity *>(pT));
        pT = NULL;
    }
    else {
        Id::ids tileCornerTopId = stage == 1? Id::tile1TopCornerLeft : Id::tile2TopCornerLeft;
        Id::ids tileId = stage == 1? Id::tile1WallLeft : Id::tile2WallLeft;
        Id::ids tileCornerBottomId = stage == 1? Id::tile1BottomCornerLeft : Id::tile2BottomCornerLeft;
        pT = new Entities::Tile(tileCornerTopId, currentPos);
        pEntityList->addEntity(static_cast<Entities::Entity *>(pT));
        pT = NULL;
        for (int i = 1; i < size - 1; i++) {
            pT = new Entities::Tile(tileId, currentPos);
            pEntityList->addEntity(static_cast<Entities::Entity *>(pT));
            pT = NULL;
            currentPos.setY(currentPos.getY() + 32.f);
        }
        pT = new Entities::Tile(tileCornerBottomId, currentPos);
        pEntityList->addEntity(static_cast<Entities::Entity *>(pT));
        pT = NULL;
    }
}

void TileMaker::makeTileBackground(Coordinates::Vector<float> initialPos,
                                  Coordinates::Vector<unsigned int> size) {
    Id::ids tileId = stage == 1? Id::tile1Background : Id::tile2Background;
    Coordinates::Vector<float> currentPos = initialPos;
    Entities::Tile* pT = NULL;
    for (int i = 0; i < size.getY(); i++) {
        for (int j = 0; j < size.getX(); j++) {
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