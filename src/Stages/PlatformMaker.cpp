#include "Stages/PlatformMaker.h"
using namespace Stages;

PlatformMaker::PlatformMaker(EntityList* pEL) {
    pEntityList = NULL;
    if (pEL)
        pEntityList = pEL;

}

PlatformMaker::~PlatformMaker() {
    pEntityList = NULL;
}

void PlatformMaker::makePlatform(int stage, Coordinates::Vector<float> initialPos, unsigned int size) {
    Coordinates::Vector<float> currentPos = initialPos;
    Entities::Tile* pT = NULL;
    Id::ids tileId = stage == 2? Id::tile2 : Id::tile1;
    for (int i = 0; i < size; i++) {
        pT = new Entities::Tile(tileId, currentPos);
        pEntityList->addEntity(static_cast<Entities::Entity*>(pT));
        pT = NULL;
        currentPos.setX(currentPos.getX() + 32.f);
    }
}