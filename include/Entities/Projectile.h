#pragma once

#include "Entities/Entity.h"
#define FIREBALL_TEXTURE_PATH "../assets/fireball.png"

namespace Entities {

    class Projectile: public Entity {

    private:

        Coordinates::Vector<float> velocity;
        bool isFacingLeft;
        float timer;

    public:

        Projectile(Coordinates::Vector<float> pos, bool isFL);

        ~Projectile() override;

        void initializeSprite() override;

        //void collide(Entity* pE, Coordinates::Vector<float> collision) override;

        void update(float dt) override;
    };
}