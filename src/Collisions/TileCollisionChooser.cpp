#include "Collisions/TileCollisionChooser.h"
using namespace Collisions;

TileCollisionChooser::TileCollisionChooser() {
    tileCollisions = new TileCollisions();
}

TileCollisionChooser::~TileCollisionChooser() {
    if (tileCollisions)
        delete tileCollisions;
}

void TileCollisionChooser::collisionChooser(Entities::Entity *pE1, Entities::Entity *pE2,
                                            Coordinates::Vector<float> collision) {

    //vertical collisions
    if ( ((int)(pE2->getId()) >= 100 &&  (int)(pE2->getId()) <= 105)
        || ((int)(pE2->getId()) >= 200 &&  (int)(pE2->getId()) <= 205) )
    {
        if ((int) (pE1->getId()) >= 1 && (int) (pE1->getId() <= 30))
        {
            if (pE1->getPosition().getY() > pE2->getPosition().getY())
                tileCollisions->roofCollision(pE1, pE2, collision);
            else
                tileCollisions->groundCollision(pE1, pE2, collision);
        }
        else
            return;
    }

    //horizontal collisions
    if( ((int)(pE2->getId()) == 106 || (int)(pE2->getId()) == 107)
             || ((int)(pE2->getId()) == 206 || (int)(pE2->getId()) == 207) )
    {
        if ((int) (pE1->getId()) >= 1 && (int) (pE1->getId() <= 30))
            tileCollisions->wallCollision(pE1,pE2,collision);
        else
            return;
    }

    //no collision in background tiles
    else if ( ((int)(pE2->getId()) == 108 || (int)(pE2->getId()) == 208) )
    {
        return;
    }

    else
        return;

}

void TileCollisionChooser::doCollision(Entities::Entity *pE1, Entities::Entity *pE2,
                                       Coordinates::Vector<float> collision) {
    collisionChooser(pE1, pE2, collision);
}

