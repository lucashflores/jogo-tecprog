#pragma once


#include "Entities/Enemy.h"

namespace Entities {


    class SmokerEnemy : public Enemy {
    private:


    public:
        SmokerEnemy(Coordinates::VectorFloat pos);

        ~SmokerEnemy() override;

        void walk();

        void idle();

        void collide(Entity* pE, Coordinates::VectorFloat Collision);

        void update(float dt) override;
    };

}