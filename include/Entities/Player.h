#pragma once

#define VELOCITY_X 0.2f
#define VELOCITY_Y 0.35f

#include "Entities/Character.h"
#include "Managers/InputManager.h"

class PlayerControl;

namespace Entities {

    class Player : public Character {
    private:
        PlayerControl* playerControl;
        bool isPlayerOne;
    public:
        Player(bool isPlayerOne=true);

        ~Player();

        void walk(bool left);

        void jump();

        void collide(Entity* pE, Coordinates::Vector<float> collision);

        void update(float dt);
    };

}