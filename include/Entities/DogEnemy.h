#pragma once

#define DOG_TERMINALVELOCITY 150.f
#define DOG_ACCELERATION 200.f
#define DOG_STOPDRAGRATE 0.996f
#define DOG_CHANGEDIRECTIONDRAGRATE 2200.f

#include "Entities/Enemy.h"

namespace Entities {


    class DogEnemy : public Enemy {
    private:


    public:
        DogEnemy(Coordinates::Vector<float> pos);

        ~DogEnemy() override;

        void walk(float dt);

        void idle();

        void collide(Entity* pE, Coordinates::Vector<float> collision);

        void update(float dt) override;
    };

}