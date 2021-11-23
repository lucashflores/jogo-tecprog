#pragma once
#include "TileCollisionManager.h"
#include "ObstacleCollisionManager.h"
#include "EntityCollisionManager.h"
#include "Id.h"

namespace Collisions {

    class CollisionChooser: ICollisionChooser {
    private:
        TileCollisionManager* tileCollisionManager;
        ObstacleCollisionManager* obstacleCollisionManager;
        EntityCollisionManager* entityCollisionManager;
        void collisionChooser(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
    public:
        CollisionChooser();
        ~CollisionChooser();
        void doCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
    };

}