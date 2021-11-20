#pragma once


#include "Entities/Player.h"
#include "Entities/Character.h"
#include "Defines/enemyafx.h"

namespace Entities {

    class Enemy : public Character {
    protected:
        bool isCommitted;
        float view_range;
        Player* player1;
        Player* player2;

        Player* target;

    public:
        Enemy(Id::ids idEnemy, unsigned int life, unsigned int dmg, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos, float view_rng);
        ~Enemy() override;

        void setPlayer(Player* player);

        void setTarget(Player* tg);

        double getTargetDist();

        Player* chooseTarget();
    };
}