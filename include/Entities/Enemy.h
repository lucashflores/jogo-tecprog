#pragma once

#include "Entities/Character.h"

namespace Entities {

    class Enemy : public Character {
    private:
        Enemy();

        bool isCommited;

    public:
        Enemy(Id::ids IdEnemy, unsigned char life, unsigned char dmg, sf::Vector2f v1);
        ~Enemy();
    };

}