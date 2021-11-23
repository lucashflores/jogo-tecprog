#include "Managers/CollisionManager.h"
using namespace Managers;

CollisionManager* CollisionManager::instance = NULL;

CollisionManager::CollisionManager() {
    collisionChooser = new Collisions::CollisionChooser();
}

CollisionManager::~CollisionManager() {
    pEntityList = NULL;
    if (collisionChooser)
        delete collisionChooser;
}

CollisionManager *CollisionManager::getInstance() {
    if (!instance)
        instance = new CollisionManager();
    return instance;
}

void CollisionManager::setEntityList(EntityList *pEL) {
    if (pEL)
        pEntityList = pEL;
}

void CollisionManager::collideAllEntities() {
    Entities::Entity* pE = NULL;
    Entities::Entity* pE2 = NULL;
    int size = pEntityList->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            pE = pEntityList->operator[](i);
            pE2 = pEntityList->operator[](j);
            //pE2 = (*pEntityList)[j];

            float distanceX = fabs(pE->getPosition().getX() - pE2->getPosition().getX());
            float distanceY = fabs(pE->getPosition().getY() - pE2->getPosition().getY());

            float hitBoxesX = (pE->getHitBox().getX() / 2.0f) + (pE2->getHitBox().getX() / 2.0f);
            float hitBoxesY = (pE->getHitBox().getY() / 2.0f) + (pE2->getHitBox().getY() / 2.0f);

            float collideInX = hitBoxesX - distanceX;
            float collideInY =  hitBoxesY - distanceY;

            Coordinates::Vector<float> collision(collideInX, collideInY);

            if (collideInY > 0.0f && collideInX > 0.0f) {
                collisionChooser->doCollision(pE, pE2, collision);
                collisionChooser->doCollision(pE2, pE, collision);
            }

            pE = NULL;
            pE2 = NULL;
        }
    }
}