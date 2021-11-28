#pragma once

#include "ICollisionChooser.h"
#include "TileCollisionDealer.h"

namespace Collisions {
    class TileCollisionManager: ICollisionChooser {
    private:
        void collisionChooser(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
        TileCollisionDealer* tileCollisions;
    public:
        TileCollisionManager();
        ~TileCollisionManager();
        void doCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
    };
}