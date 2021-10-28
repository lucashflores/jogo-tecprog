#pragma once

#include <SFML/Graphics.hpp>
#include <map>

namespace Managers {

    class InputManager {
    private:
        sf::Keyboard::Key keyPressed;
        std::map<sf::Keyboard::Key, bool> keysDown;
        sf::Keyboard::Key keyReleased;

        InputManager();

        static InputManager *instance;
    public:
        ~InputManager();

        static InputManager *getInstance();

        void handleKeyPressed(sf::Keyboard::Key key);

        void handleKeyReleased(sf::Keyboard::Key key);

        sf::Keyboard::Key getKeyPressed();

        bool isKeyDown(sf::Keyboard::Key key);

        sf::Keyboard::Key getKeyReleased();

        bool anyKeyPressed();
    };

}