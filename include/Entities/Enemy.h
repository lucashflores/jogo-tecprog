#pragma once

#include "Entities/Character.h"

namespace Entities {

    class Enemy : public Character {
    private:
        Enemy();

        bool isCommited;

    public:
        Enemy(Id::ids idEnemy, unsigned char life, unsigned char dmg, Coordinates::VectorFloat size, Coordinates::VectorFloat hit, Coordinates::VectorFloat pos);
        ~Enemy();
    };

}