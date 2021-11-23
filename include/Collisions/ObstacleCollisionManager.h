#pragma once
#include "ICollisionChooser.h"
#include "ObstacleCollisionDealer.h"

namespace Collisions {
    class ObstacleCollisionManager: ICollisionChooser {
    private:
        void collisionChooser(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
        ObstacleCollisionDealer* obstacleCollisions;
    public:
        ObstacleCollisionManager();
        ~ObstacleCollisionManager();
        void doCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
    };
}