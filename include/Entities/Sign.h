#pragma once
#include "Entities/Obstacle.h"

namespace Entities {
    class Sign: public Obstacle {
    public:
        Sign(Coordinates::Vector<float> pos);
        ~Sign();
        void collide(Entity* pE, Coordinates::Vector<float> collision);
    };
}