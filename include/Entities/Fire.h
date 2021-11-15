#pragma once
#include "Obstacle.h"

namespace Entities {
    class Fire: public Obstacle {
        Fire(Coordinates::Vector<float> pos);
        ~Fire();
        void collide(Entity* pE, Coordinates::Vector<float> collision);
    };
}