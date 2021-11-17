#pragma once
#include "Obstacle.h"

namespace Entities {
    class Fire: public Obstacle {
    public:
        Fire(Coordinates::Vector<float> pos);
        ~Fire();
        void collide(Entity* pE, Coordinates::Vector<float> collision);
        void update(float dt);
    };
}