#pragma once

#include "Entity.h"

namespace Entities {

    class Obstacle : public Entity {
    private:
        unsigned int damage;
    public:
        Obstacle(Id::ids i, Coordinates::VectorFloat size, Coordinates::VectorFloat hit, Coordinates::VectorFloat pos, unsigned int d = 0);
        virtual ~Obstacle();
        virtual void collide(Entity* pE) = 0;
        void update(float dt);
    };


}