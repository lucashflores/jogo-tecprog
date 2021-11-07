#pragma once

#include "Entity.h"

namespace Entities {

    class Obstacle : public Entity {
    private:
        unsigned char damage;
    public:
        Obstacle(sf::Vector2f pos, unsigned char d = 0);
        ~Obstacle();
        sf::FloatRect getHitBox();
        void collide(Entity* pE);
    };


}