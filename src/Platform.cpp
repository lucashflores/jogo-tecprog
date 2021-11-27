#include "Platform.h"

Platform::Platform(Id::ids id, Coordinates::Vector<float> pos, int size, EntityList* pEL) {
    if (pEL) {
        pEntityList = pEL;
        Coordinates::Vector<float> currentPos = pos;
        Entities::Tile* pT = NULL;

        for (int i = 0; i < size; i++) {
            pT = new Entities::Tile(id, currentPos);
            tileList.pushBack(pT);
            pEntityList->addEntity(static_cast<Entities::Entity*>(pT));
            pT = NULL;
            currentPos.setX(currentPos.getX() + 32.f);
        }
    }
    else
        pEntityList = NULL;
}

Platform::~Platform() {
    pEntityList = NULL;
}
