#pragma once


#include "Entities/Enemy.h"

namespace Entities {


    class SmokerEnemy : public Enemy {
    private:


    public:
        SmokerEnemy(Coordinates::Vector<float> pos);

        ~SmokerEnemy() override;

        void walk();

        void idle();

        void collide(Entity* pE, Coordinates::Vector<float> collision);

        void update(float dt) override;
    };

}