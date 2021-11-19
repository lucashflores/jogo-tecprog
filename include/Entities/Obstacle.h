#pragma once

#include "Entity.h"

namespace Entities {

    class Obstacle : public Entity {
    private:
        unsigned int damage;
    public:
        Obstacle(Id::ids i, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos, unsigned int d = 0);
        virtual ~Obstacle();
        virtual void collide(Entity* pE, Coordinates::Vector<float> collision) = 0;
        void initializeSprite() override;
        void update(float dt);
    };
}