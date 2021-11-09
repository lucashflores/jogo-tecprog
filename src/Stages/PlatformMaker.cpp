#include "Stages/PlatformMaker.h"
using namespace Stages;

PlatformMaker::PlatformMaker() {
    pEntityList = Entities::EntityList::getInstance();

}

PlatformMaker::~PlatformMaker() {
    pEntityList = NULL;
}

void PlatformMaker::makePlatform(Coordinates::VectorFloat initialPos, unsigned int size) {
    Coordinates::VectorFloat currentPos = initialPos;
    Entities::Obstacle* pO = NULL;
    for (int i = 0; i < size; i++) {
        pO = new Entities::Obstacle(currentPos, 0);
        pO = NULL;
        currentPos.x += 32.f;
    }
}