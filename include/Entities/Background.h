#pragma once

#include "Entity.h"

namespace Entities {

    class Background: public Entity {
    public:
        Background(Id::ids id);
        ~Background();
        void collide(Entity* pE);
        void update(sf::Vector2f pos);
    };
}