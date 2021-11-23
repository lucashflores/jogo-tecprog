#pragma once
#include "ICollisionChooser.h"
#include "EntityCollisionDealer.h"

namespace Collisions {
    class EntityCollisionManager: ICollisionChooser {
    private:
        void collisionChooser(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
        EntityCollisionDealer* entityCollisions;
    public:
        EntityCollisionManager();
        ~EntityCollisionManager();
        void doCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
    };
}