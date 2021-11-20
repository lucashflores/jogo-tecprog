#pragma once
#include "TileCollisionChooser.h"
#include "ObstacleCollisionChooser.h"
#include "EntityCollisionChooser.h"
#include "Id.h"

namespace Collisions {

    class CollisionChooser: ICollisionChooser {
    private:
        TileCollisionChooser* tileCollisionChooser;
        ObstacleCollisionChooser* obstacleCollisionChooser;
        EntityCollisionChooser* entityCollisionChooser;
        void collisionChooser(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
    public:
        CollisionChooser();
        ~CollisionChooser();
        void doCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision);
    };

}