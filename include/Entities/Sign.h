#pragma once
#include "Entities/Obstacle.h"

namespace Entities {
    class Sign: public Obstacle {
    public:
        Sign(Coordinates::Vector<float> pos);

        ~Sign();

        void initializeSprite();

        void save();

        void restore();

        void saveEntity(std::ofstream& out) const;
    };
}