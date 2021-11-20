#pragma once
#include "ICollisionChooser.h"
#include "EntityCollisions.h"

namespace Collisions {
    class EntityCollisionChooser: ICollisionChooser {
    private:
        void collisionChooser(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
        EntityCollisions* entityCollisions;
    public:
        EntityCollisionChooser();
        ~EntityCollisionChooser();
        void doCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
    };
}