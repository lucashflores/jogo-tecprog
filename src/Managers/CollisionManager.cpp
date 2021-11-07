#include "Managers/CollisionManager.h"
using namespace Managers;

CollisionManager* CollisionManager::instance = NULL;

CollisionManager::CollisionManager() {
    pEntityList = Entities::EntityList::getInstance();
}

CollisionManager::~CollisionManager() {
    pEntityList = NULL;
}

CollisionManager *CollisionManager::getInstance() {
    if (!instance)
        instance = new CollisionManager();
    return instance;
}

void CollisionManager::collideAllEntities() {
    Entities::Entity* pE = NULL;
    Entities::Entity* pE2 = NULL;
    for (auto it = pEntityList->begin(); it != pEntityList->end(); it++) {
        for (auto it2 = pEntityList->begin(); it2 != pEntityList->end(); it2++) {
            pE = (*it);
            pE2 = (*it2);
            if (pE && pE2) {
                if (pE->getHitBox().intersects(pE2->getHitBox())) {
                    pE->collide(pE2);
                    pE2->collide(pE);
                }
            }
            pE = NULL;
            pE2 = NULL;
        }
    }
}