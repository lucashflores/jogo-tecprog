#pragma once


#define PLAYER1_IDLE_TEXTURE "../assets/biker_idle.png"
#define PLAYER1_RUNNING_TEXTURE_PATH "../assets/biker_run.png"
#define PLAYER1_RUNNING_LEFT_TEXTURE_PATH "../assets/biker_run_left.png"

#include "Entities/Character.h"
#include "Managers/InputManager.h"

class PlayerControl;

namespace Entities {

    class Player : public Character {
    private:
        PlayerControl* playerControl;
        bool isPlayerOne;
        bool isPlayerOnGround;
    public:
        Player(bool isPlayerOne=true);

        ~Player();

        void setAnimation();

        bool isWalking() const;

        bool isFacingLeft() const;

        void setIsOnGround(bool isOnGround);

        const bool getIsOnGround() const;

        void collide(Entity* pE);

        void update(float dt);
    };

}