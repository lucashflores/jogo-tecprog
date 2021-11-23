#pragma once

#include "Entities/Character.h"

namespace Collisions {
    class TileCollisions {
    public:
        TileCollisions();
        ~TileCollisions();
        void groundCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
        void wallCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
        void roofCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
    };
}