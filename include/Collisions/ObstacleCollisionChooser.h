#pragma once
#include "ICollisionChooser.h"
#include "ObstacleCollisions.h"

namespace Collisions {
    class ObstacleCollisionChooser: ICollisionChooser {
    private:
        void collisionChooser(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
        ObstacleCollisions* obstacleCollisions;
    public:
        ObstacleCollisionChooser();
        ~ObstacleCollisionChooser();
        void doCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
    };
}