#pragma once

#include "Entities/Entity.h"
#define SMOKE_TEXTURE_PATH "../assets/smoke.png"

namespace Entities {

    class Smoke : public Entity{
    private:

        float timer;

    public:

        Smoke(Coordinates::Vector<float> pos);
        ~Smoke();

        void initializeSprite() override;
        void update(float dt) override;
    };
}