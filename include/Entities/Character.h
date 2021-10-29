#pragma once

#include "Entity.h"

namespace Entities {

    class Character: public Entity {
    protected:
        Animation *animation;
        sf::Vector2f velocity;
    public:
        Character(sf::Vector2f v);
        virtual ~Character();

    };
}