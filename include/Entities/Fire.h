#pragma once
#include "Obstacle.h"

namespace Entities {
    class Fire: public Obstacle {
    public:
        Fire(Coordinates::Vector<float> pos);

        ~Fire();

        void initializeSprite();

        void update(float dt);

        void saveEntity(std::ofstream& out) const;
    };
}