#pragma once

#include <SFML/Graphics.hpp>
#include <map>

namespace Managers {

    class InputManager {
    private:
        std::map<std::string, sf::Keyboard::Key> keyMap;

        sf::Keyboard::Key keyPressed;
        std::map<sf::Keyboard::Key, bool> keysDown;
        sf::Keyboard::Key keyReleased;

        InputManager();

        static InputManager *instance;
    public:
        ~InputManager();

        sf::Keyboard::Key getKey(std::string key);

        static InputManager *getInstance();

        void handleKeyPressed(sf::Keyboard::Key key);

        void handleKeyReleased(sf::Keyboard::Key key);

        bool wasKeyPressed(std::string key);

        bool isKeyDown(std::string key);

        bool wasKeyReleased(std::string key);

    };

}