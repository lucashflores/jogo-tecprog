#pragma once
#include "Entities/Obstacle.h"


namespace Entities {

    class Box: public Obstacle {
    public:
        Box(Coordinates::Vector<float> pos);
        ~Box();
        void collide(Entity* pE, Coordinates::Vector<float> collision);
    };

}