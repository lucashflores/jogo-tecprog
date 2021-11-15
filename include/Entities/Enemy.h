#pragma once


#include "Entities/Player.h"
#include "Entities/Character.h"

namespace Entities {

    class Enemy : public Character {
    protected:
        bool isCommitted;
        float view_range;
        Player* player1;
        Player* player2;

        Player* target;

    public:
        Enemy(Id::ids idEnemy, unsigned char life, unsigned char dmg, Coordinates::VectorFloat size, Coordinates::VectorFloat hit, Coordinates::VectorFloat pos, float view_rng);
        ~Enemy() override;

        void setPlayer(Player* player);

        void setTarget(Player* tg);

        Player* chooseTarget();
    };
}