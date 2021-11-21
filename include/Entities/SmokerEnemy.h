#pragma once

#include "Entities/Smoke.h"
#include "Entities/Enemy.h"
#include "EntityList.h"

namespace Entities {


    class SmokerEnemy : public Enemy {
    private:

        EntityList* smokerEntityList;

    public:
        SmokerEnemy(Coordinates::Vector<float> pos);

        ~SmokerEnemy() override;

        void walk(float dt);

        void idle();

        void attack(Character* pChar);

        void initializeSprite();

        void setEntityList(EntityList* EL);

        //void collide(Entity* pE, Coordinates::Vector<float> collision);

        void update(float dt) override;
    };

}