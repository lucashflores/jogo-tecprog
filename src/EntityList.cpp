#include "EntityList.h"


EntityList::EntityList(): entityList() {
}

EntityList::~EntityList() {
    Entities::Entity* pE = NULL;
    for (iterator it = entityList.begin(); it != entityList.end(); it++) {
        pE = (*it);
        if (pE)
            delete pE;
        pE = NULL;
    }

    entityList.clear();

}

int EntityList::getSize() {
    return entityList.getSize();
}

void EntityList::addEntity(Entities::Entity* pE) {
    entityList.pushBack(pE);
}

void EntityList::removeEntity(Entities::Entity* pE) {
    entityList.removeElement(pE);
    return;
}

Entities::Entity* EntityList::operator[](int pos) {
    return entityList[pos];
}


void EntityList::renderAllEntities() {
    Entities::Entity* pE = NULL;
    int size = getSize();
    for (int i = 0; i < size; i++) {
        pE = entityList[i];
        pE->render();
        pE = NULL;
    }
    pE = NULL;
}


