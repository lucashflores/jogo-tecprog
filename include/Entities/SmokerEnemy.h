#pragma once


#include "Entities/Enemy.h"

namespace Entities {


    class SmokerEnemy : public Enemy {
    private:

    public:
        SmokerEnemy(Coordinates::Vector<float> pos);

        ~SmokerEnemy() override;

        void walk(float dt);

        void idle();

        void attack(Character* pChar);

        void initializeSprite();

        void collide(Entity* pE, Coordinates::Vector<float> collision);

        void update(float dt) override;
    };

}