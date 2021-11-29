#include "EntityList.h"
#include "Concurrent/BossThread.h"

EntityList::EntityList(): entityList() {
}

EntityList::~EntityList() {

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
}

void EntityList::removeAndDeleteEntity(Entities::Entity *pE) {
    entityList.removeAndDeleteElement(pE);
}

Entities::Entity* EntityList::operator[](int pos) {
    return entityList[pos];
}

void EntityList::renderAllEntities() {

    Entities::Entity* pE = NULL;
    int size = getSize();
    for (int i = size-1; i >= 0; i--) {
        pE = entityList[i];
        pE->render();
        pE = NULL;
    }
    pE = NULL;

}


void EntityList::updateAllEntities(float dt) {


    Entities::Entity* pE = NULL;
    int size = getSize();
    for (int i = 0; i < size; i++) {
        if (entityList[i]->getIsAlive()) {
            pE = entityList[i];
            pE->update(dt);
            pE = NULL;
        }
    }
    pE = NULL;
}

EntityList::iterator EntityList::begin() {
    return entityList.begin();
}

EntityList::iterator EntityList::end() {
    return entityList.end();
}