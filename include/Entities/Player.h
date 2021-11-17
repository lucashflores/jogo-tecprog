#pragma once


#define PLAYER1_IDLE_TEXTURE "../assets/biker_idle.png"
#define PLAYER1_RUNNING_TEXTURE_PATH "../assets/biker_run.png"

#define VELOCITY_X 200.0f
#define VELOCITY_Y 380.0f

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