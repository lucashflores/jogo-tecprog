#include "Collisions/EntityCollisionChooser.h"
using namespace Collisions;


EntityCollisionChooser::EntityCollisionChooser(): ICollisionChooser() {
    entityCollisions = new EntityCollisions();
}

EntityCollisionChooser::~EntityCollisionChooser() {
    if (entityCollisions)
        delete entityCollisions;
}

void EntityCollisionChooser::collisionChooser(Entities::Entity *pE1, Entities::Entity *pE2,
                                              Coordinates::Vector<float> collision) {
    if (pE2->getId() == Id::projectile) {
        if (pE1->getId() == Id::player1 || pE1->getId() == Id::player2) {
            entityCollisions->projectileCollision(pE1, pE2, collision);
        }
        else
            return;
    }
    else if (pE2->getId() == Id::smoke) {
        if (pE1->getId() == Id::player1 || pE1->getId() == Id::player2) {
            entityCollisions->smokeCollision(pE1, pE2, collision);
        }
        else
            return;
    }
    else if (pE2->getId() == Id::dog || pE2->getId() == Id::smoker || pE2->getId() == Id::punk){
        if (pE1->getId() == Id::player1 || pE1->getId() == Id::player2) {
            entityCollisions->enemyCollision(pE1, pE2, collision);
        }
        else
            return;
    }
    else if (pE2->getId() == Id::player1 || pE2->getId() == Id::player2) {
        if (pE1->getId() == Id::dog || pE1->getId() == Id::smoker || pE1->getId() == Id::punk || pE1->getId() == Id::projectile)
            entityCollisions->playerCollision(pE1, pE2, collision);
    }
    else
        return;
}

void EntityCollisionChooser::doCollision(Entities::Entity *pE1, Entities::Entity *pE2,
                                              Coordinates::Vector<float> collision) {
    collisionChooser(pE1, pE2, collision);
}