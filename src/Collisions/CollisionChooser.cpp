#include "Collisions/CollisionChooser.h"
using namespace Collisions;

CollisionChooser::CollisionChooser() {
    tileCollisionManager = new TileCollisionManager();
    entityCollisionManager = new EntityCollisionManager();
    obstacleCollisionManager = new ObstacleCollisionManager();
}

CollisionChooser::~CollisionChooser() {
    if (tileCollisionManager)
        delete tileCollisionManager;
    if (entityCollisionManager)
        delete entityCollisionManager;
    if (obstacleCollisionManager)
        delete obstacleCollisionManager;
}

//Complex operations start - private
void CollisionChooser::collisionChooser(Entities::Entity* pE1, Entities::Entity* pE2,
                                        Coordinates::Vector<float> collision)
{
    if (pE1->getId() == pE2->getId())
        return;
    else if ( pE2->getId() == Id::tile1 || pE2->getId() == Id::tile2 ) {
        tileCollisionManager->doCollision(pE1, pE2, collision);
    }
    else if ( ((int)pE2->getId() >= 300) && ((int)(pE2->getId()) <= 600) ){
        obstacleCollisionManager->doCollision(pE1, pE2, collision);
    }
    else if( ((int)pE2->getId() >= 1) && ((int)(pE2->getId()) <= 99) ){
        entityCollisionManager->doCollision(pE1, pE2, collision);
    }
    else {
        return ;
    }
}


void CollisionChooser::doCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision) {
    collisionChooser(pE1, pE2, collision);
}