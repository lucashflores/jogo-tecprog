#pragma once

#include "Entities/Character.h"

namespace Collisions {
    class TileCollisionDealer {
    public:
        TileCollisionDealer();
        ~TileCollisionDealer();
        void groundCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
        void wallCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
        void roofCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
    };
}