#include "Stages/PlatformMaker.h"
using namespace Stages;

PlatformMaker::PlatformMaker(EntityList* pEL) {
    if (pEL)
        pEntityList = pEL;

}

PlatformMaker::~PlatformMaker() {
    pEntityList = NULL;
}

void PlatformMaker::makePlatform(Id::ids obstacleId, Coordinates::Vector<float> initialPos, unsigned int size) {
    Coordinates::Vector<float> currentPos = initialPos;
    Entities::Tile* pT = NULL;
    for (int i = 0; i < size; i++) {
        pT = new Entities::Tile(obstacleId, currentPos);
        pEntityList->addEntity(static_cast<Entities::Entity*>(pT));
        pT = NULL;
        currentPos.setX(currentPos.getX() + 32.f);
    }
}