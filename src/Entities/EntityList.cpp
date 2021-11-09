#include "EntityList.h"
using namespace Entities;

EntityList* EntityList::instance = NULL;

EntityList::EntityList(): entityList() {
}

EntityList::~EntityList() {
    Entity* pE = NULL;
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

void EntityList::addEntity(Entity* pE) {
    if (pE)
        entityList.push_back(pE);
}

void EntityList::removeEntity(Entity* pE) {
    Entity* paux = NULL;
    for (auto it = entityList.begin(); it != entityList.end(); it++) {
        paux = (*it);
        if (paux) {
            if (paux == pE) {
                delete paux;
            }
        }
        paux = NULL;
    }

}

std::list<Entity *>::iterator EntityList::begin() {
    return entityList.begin();
}

std::list<Entity *>::iterator EntityList::end() {
    return entityList.end();
}


void EntityList::renderAllEntities() {
    Entity* pE = NULL;
    for (auto it = begin(); it != end(); it++) {
        pE = (*it);
        if (pE)
            pE->render();
        pE = NULL;
    }
}

