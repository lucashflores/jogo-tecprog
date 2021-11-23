#pragma once

#include "Entities/Character.h"
#include "Entities/Obstacle.h"

namespace Collisions {
    class ObstacleCollisions {
    public:
        ObstacleCollisions();
        ~ObstacleCollisions();
        void barrelCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
        void fireCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
        void signCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
        void oilTileCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
    };
}