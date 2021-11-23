#include "Collisions/TileCollisionManager.h"
using namespace Collisions;

TileCollisionManager::TileCollisionManager() {
    tileCollisions = new TileCollisionDealer();
}

TileCollisionManager::~TileCollisionManager() {
    if (tileCollisions)
        delete tileCollisions;
}

void TileCollisionManager::collisionChooser(Entities::Entity *pE1, Entities::Entity *pE2,
                                            Coordinates::Vector<float> collision) {

    if ((int) (pE1->getId()) >= 1 && (int) (pE1->getId() <= 30)) {
        if (collision.getX() > collision.getY()) {
            if (pE1->getPosition().getY() <  pE2->getPosition().getY())
                tileCollisions->groundCollision(pE1, pE2, collision);
            else
                tileCollisions->roofCollision(pE1, pE2, collision);
        }
        else
            tileCollisions->wallCollision(pE1, pE2, collision);
    }
    else
        return ;
}

void TileCollisionManager::doCollision(Entities::Entity *pE1, Entities::Entity *pE2,
                                       Coordinates::Vector<float> collision) {
    collisionChooser(pE1, pE2, collision);
}

