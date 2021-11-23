#include "Collisions/ObstacleCollisionChooser.h"
using namespace Collisions;

ObstacleCollisionChooser::ObstacleCollisionChooser() : ICollisionChooser() {
    obstacleCollisions = new ObstacleCollisions();
}

ObstacleCollisionChooser::~ObstacleCollisionChooser() {
    if (obstacleCollisions)
        delete obstacleCollisions;
}

void ObstacleCollisionChooser::collisionChooser(Entities::Entity *pE1, Entities::Entity *pE2,
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

void ObstacleCollisionChooser::doCollision(Entities::Entity *pE1, Entities::Entity *pE2,
                                           Coordinates::Vector<float> collision) {
    collisionChooser(pE1, pE2, collision);
}