#pragma once

#define DOG_TERMINALVELOCITY 180.f
#define DOG_ACCELERATION 350.f
#define DOG_STOPDRAGRATE 0.996f
#define DOG_CHANGEDIRECTIONDRAGRATE 8600.f

#include "Entities/Enemy.h"

namespace Entities {


    class DogEnemy : public Enemy {
    private:

        float idleTimer;

    public:
        DogEnemy(Coordinates::Vector<float> pos);

        ~DogEnemy() override;

        void walk(float dt);

        void idle(float dt);

        void attack(Character* pChar);

        void initializeSprite();

        void collide(Entity* pE, Coordinates::Vector<float> collision) override;

        void update(float dt) override;
    };

}