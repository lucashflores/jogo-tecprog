#pragma once

#include "Entities/Entity.h"
#define SMOKE_TEXTURE_PATH "../assets/smoke.png"

namespace Entities {

    class Smoke : public Entity{
    private:

        float timer;
        float cooldowntimer;

    public:

        Smoke(Coordinates::Vector<float> pos);

        ~Smoke();

        unsigned int getDamage();

        float getTimer();

        float getCooldown();

        void setCooldown(float cd);

        void initializeSprite() override;

        void update(float dt) override;

        void saveEntity(std::ofstream& out) const;
    };
}