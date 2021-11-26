#pragma once

#include "Entities/Enemy.h"
#include "Entities/Projectile.h"
#include "EntityList.h"
#include "Stages/ProjectileMaker.h"

namespace Entities {

    class PunkBoss : public Enemy {
    private:
        Stages::ProjectileMaker* projectileMaker;

    public:
        PunkBoss(Coordinates::Vector<float> pos);

        ~PunkBoss() override;

        void idle(float dt);

        void attack(Character* pChar);

        void initializeSprite();

        void setProjectileMaker(Stages::ProjectileMaker* pPM);

        void update(float dt) override;

        void saveEntity(std::ofstream& out) const;
    };
}