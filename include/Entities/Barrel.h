#pragma once
#include "Entities/Obstacle.h"


namespace Entities {

    class Barrel: public Obstacle {
    public:
        Barrel(Coordinates::Vector<float> pos);
        ~Barrel();
        void collide(Entity* pE, Coordinates::Vector<float> collision);
    };

}