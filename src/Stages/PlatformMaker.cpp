#include "Stages/PlatformMaker.h"
using namespace Stages;

PlatformMaker::PlatformMaker() {
    pEntityList = Entities::EntityList::getInstance();

}

PlatformMaker::~PlatformMaker() {
    pEntityList = NULL;
}

void PlatformMaker::makePlatform(sf::Vector2f initialPos, unsigned int size) {
    sf::Vector2f currentPos = initialPos;
    Entities::Obstacle* pO = NULL;
    for (int i = 0; i < size; i++) {
        pO = new Entities::Obstacle(currentPos, 0);
        pEntityList->addEntity(pO);
        pO = NULL;
        currentPos.x += 32.f;
    }
}