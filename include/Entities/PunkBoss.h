#pragma once

#include "Entities/Enemy.h"
#include "Entities/Projectile.h"
#include "EntityList.h"

namespace Entities {

    class PunkBoss : public Enemy {
    private:
        EntityList* bossEntityList;

    public:
        PunkBoss(Coordinates::Vector<float> pos);

        ~PunkBoss() override;

        void idle(float dt);

        void attack(Character* pChar);

        void initializeSprite();

        void setEntityList(EntityList* EL);

        void update(float dt) override;

        void saveEntity(std::ofstream& out) const;
    };
}