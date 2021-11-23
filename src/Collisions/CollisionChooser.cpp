#include "Collisions/CollisionChooser.h"
using namespace Collisions;

CollisionChooser::CollisionChooser() {
    tileCollisionChooser = new TileCollisionChooser();
    entityCollisionChooser = new EntityCollisionChooser();
    obstacleCollisionChooser = new ObstacleCollisionChooser();
}

CollisionChooser::~CollisionChooser() {
    if (tileCollisionChooser)
        delete tileCollisionChooser;
    if (entityCollisionChooser)
        delete entityCollisionChooser;
    if (obstacleCollisionChooser)
        delete obstacleCollisionChooser;
}

//Complex operations start - private
void CollisionChooser::collisionChooser(Entities::Entity* pE1, Entities::Entity* pE2,
                                        Coordinates::Vector<float> collision)
{
    if (pE1->getId() == pE2->getId())
        return;
    else if ( ((int)(pE2->getId()) >= 100) && ((int)(pE2->getId()) <= 208) ){
        tileCollisionChooser->doCollision(pE1, pE2, collision);
    }
    else if ( ((int)pE2->getId() >= 300) && ((int)(pE2->getId()) <= 600) ){
        obstacleCollisionChooser->doCollision(pE1, pE2, collision);
    }
    else if( ((int)pE2->getId() >= 1) && ((int)(pE2->getId()) <= 99) ){
        entityCollisionChooser->doCollision(pE1, pE2, collision);
    }
    else {
        return ;
    }
}

//Facade
void CollisionChooser::doCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision) {
    collisionChooser(pE1, pE2, collision);
}