#pragma once

#include "Entity.h"
#include "Defines/objectsafx.h"

namespace Entities {

    class Obstacle : public Entity {
    public:
        Obstacle(Id::ids i, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos, unsigned int d = 0);

        virtual ~Obstacle();

        unsigned int getDamage();

        void update(float dt);

        void saveEntity(std::ofstream& out);

        void restoreEntity(std::ifstream& in);
    };
}