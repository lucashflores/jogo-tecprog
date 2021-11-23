#pragma once

#include "Entities/Entity.h"

namespace Collisions {
    class ICollisionChooser {

    protected:
        virtual void collisionChooser(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision) = 0;
    public:
        virtual void doCollision(Entities::Entity* pE1, Entities::Entity* pE2, Coordinates::Vector<float> collision) = 0;
    };

}