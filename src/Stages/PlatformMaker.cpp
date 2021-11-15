#include "Stages/PlatformMaker.h"
using namespace Stages;

PlatformMaker::PlatformMaker() {
    pEntityList = EntityList::getInstance();

}

PlatformMaker::~PlatformMaker() {
    pEntityList = NULL;
}

void PlatformMaker::makePlatform(Id::ids obstacleId, Coordinates::Vector<float> initialPos, unsigned int size) {
    Coordinates::Vector<float> currentPos = initialPos;
    Entities::Tile* pT = NULL;
    for (int i = 0; i < size; i++) {
        pT = new Entities::Tile(obstacleId, currentPos);
        pT = NULL;
        currentPos.setX(currentPos.getX() + 32.f);
    }
}