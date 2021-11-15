#include "EntityList.h"

EntityList* EntityList::instance = NULL;

EntityList::EntityList(): entityList() {
}

EntityList::~EntityList() {
    Entities::Entity* pE = NULL;
    for (auto it = entityList.begin(); it != entityList.end(); it++) {
        pE = (*it);
        if (pE)
            delete pE;
        pE = NULL;
    }

    entityList.clear();
}

EntityList* EntityList::getInstance() {
    if (instance == NULL)
        instance = new EntityList();
    return instance;
}

int EntityList::getSize() {
    return entityList.size();
}

void EntityList::addEntity(Entities::Entity* pE) {
    entityList.push_back(pE);
}

void EntityList::removeEntity(Entities::Entity* pE) {
    //entityList.removeInfo(pE);
    return;
}

Entities::Entity *EntityList::operator[](int pos) {
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


