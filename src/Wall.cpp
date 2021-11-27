#include "Wall.h"

Wall::Wall(Id::ids id, Coordinates::Vector<float> pos, int size, EntityList* pEL) {
    if (pEL) {
        pEntityList = pEL;
        Coordinates::Vector<float> currentPos = pos;
        Entities::Tile* pT = NULL;

        for (int i = 0; i < size; i++) {
            pT = new Entities::Tile(id, currentPos);
            TileList.pushBack(pT);
            pEntityList->addEntity(static_cast<Entities::Entity*>(pT));
            pT = NULL;
            currentPos.setY(currentPos.getY() + 32.f);
        }
    }
    else
        pEntityList = NULL;
}

Wall::~Wall() {
    pEntityList = NULL;
}