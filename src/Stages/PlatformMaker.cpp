#include "Stages/PlatformMaker.h"
using namespace Stages;

PlatformMaker::PlatformMaker() {
    pEntityList = Entities::EntityList::getInstance();

}

PlatformMaker::~PlatformMaker() {
    pEntityList = NULL;
}

void PlatformMaker::makePlatform(Id::ids obstacleId, Coordinates::VectorFloat initialPos, unsigned int size) {
    Coordinates::VectorFloat currentPos = initialPos;
    Entities::Obstacle* pO = NULL;
    for (int i = 0; i < size; i++) {
        pO = new Entities::Tile(obstacleId, currentPos);
        pO = NULL;
        currentPos.setX(currentPos.getX() + 32.f);
    }
}