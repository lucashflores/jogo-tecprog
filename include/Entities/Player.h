#pragma once

#include "Entities/Entity.h"
#include "Managers/InputManager.h"

namespace Entities {

    class Player : public Entity {
    private:
        Managers::InputManager *pInputManager;
        std::vector<sf::Keyboard::Key> controls;
    public:
        Player(sf::RectangleShape shape, sf::Texture *text, sf::Vector2f pos, sf::Vector2f v);

        ~Player();

        void setInputManager(Managers::InputManager *pIM);

        bool isWalking();

        bool isFacingLeft();

        void move();

        void update(float dt);
    };

}