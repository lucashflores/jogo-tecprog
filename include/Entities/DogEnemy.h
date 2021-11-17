#pragma once

#define DOG_TERMINALVELOCITY 150.f
#define DOG_ACCELERATION 220.f
#define DOG_STOPDRAGRATE 0.996f
#define DOG_CHANGEDIRECTIONDRAGRATE 2600.f

#include "Entities/Enemy.h"

namespace Entities {


    class DogEnemy : public Enemy {
    private:


    public:
        DogEnemy(Coordinates::Vector<float> pos);

        ~DogEnemy() override;

        void walk(float dt);

        void idle();

        void attack(Character* pChar) override;

        void initializeSprite();

        void collide(Entity* pE, Coordinates::Vector<float> collision) override;

        void update(float dt) override;
    };

}