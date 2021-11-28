#pragma once

#include "Entities/Smoke.h"
#include "Entities/Enemy.h"
#include "EntityList.h"
#include "Stages/ProjectileMaker.h"

namespace Entities {


    class SmokerEnemy : public Enemy {
    private:
        Stages::ProjectileMaker* projectileMaker;

    public:
        SmokerEnemy(Coordinates::Vector<float> pos);

        ~SmokerEnemy() override;

        void walk(float dt);

        void idle();

        void attack(Character* pChar);

        void initializeSprite();

        void setProjectileMaker(Stages::ProjectileMaker* pPM);

        void update(float dt) override;

        void saveEntity(std::ofstream& out) const;
    };

}