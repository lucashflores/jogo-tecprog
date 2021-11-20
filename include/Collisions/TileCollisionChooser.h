#pragma once

#include "ICollisionChooser.h"
#include "TileCollisions.h"

namespace Collisions {
    class TileCollisionChooser: ICollisionChooser {
    private:
        void collisionChooser(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
        TileCollisions* tileCollisions;
    public:
        TileCollisionChooser();
        ~TileCollisionChooser();
        void doCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
    };
}