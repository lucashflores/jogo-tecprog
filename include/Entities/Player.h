#pragma once

#define VELOCITY_X 0.6f
#define VELOCITY_Y 0.0f
#define PLAYER1_IDLE_TEXTURE "../assets/biker_idle.png"

#include "Entities/Character.h"
#include "Managers/InputManager.h"

namespace Entities {

    class Player : public Character {
    private:
        Managers::InputManager *pInputManager;
        std::vector<sf::Keyboard::Key> controls;
        bool isPlayerOne;
    public:
        Player(bool isPlayerOne=true);

        ~Player();

        void setInputManager(Managers::InputManager *pIM);

        bool isWalking() const;

        bool isFacingLeft() const;

        void move();

        void update(float dt);
    };

}