#pragma once

#include "Entities/Character.h"

namespace Collisions {
    class EntityCollisions {
    public:
        EntityCollisions();
        ~EntityCollisions();
        void enemyCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
        void playerCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
        void projectileCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
    };
}