#include "Collisions/ObstacleCollisionManager.h"
using namespace Collisions;

ObstacleCollisionManager::ObstacleCollisionManager() : ICollisionChooser() {
    obstacleCollisions = new ObstacleCollisionDealer();
}

ObstacleCollisionManager::~ObstacleCollisionManager() {
    if (obstacleCollisions)
        delete obstacleCollisions;
}

void ObstacleCollisionManager::collisionChooser(Entities::Entity *pE1, Entities::Entity *pE2,
                                                Coordinates::Vector<float> collision) {
    if (pE2->getId() == Id::oilTile)
        obstacleCollisions->oilTileCollision(pE1, pE2, collision);
    else if (pE2->getId() == Id::fire)
        obstacleCollisions->fireCollision(pE1, pE2, collision);
    else if (pE2->getId() == Id::barrel)
        obstacleCollisions->barrelCollision(pE1, pE2, collision);
    else if (pE2->getId() == Id::sign)
        obstacleCollisions->signCollision(pE1, pE2, collision);
    else
        return ;
}

void ObstacleCollisionManager::doCollision(Entities::Entity *pE1, Entities::Entity *pE2,
                                           Coordinates::Vector<float> collision) {
    collisionChooser(pE1, pE2, collision);
}