#include "Managers/InputManager.h"
using namespace Managers;

InputManager* InputManager::instance = NULL;

InputManager *InputManager::getInstance() {
    if (instance == NULL)
        instance = new InputManager();
    return instance;
}

InputManager::InputManager() {
    keyMap["A"] = sf::Keyboard::A;
    keyMap["D"] = sf::Keyboard::D;
    keyMap["S"] = sf::Keyboard::S;
    keyMap["W"] = sf::Keyboard::W;
    keyMap["Space"] = sf::Keyboard::Space;


    keysDown[sf::Keyboard::A] = false;
    keysDown[sf::Keyboard::W] = false;
    keysDown[sf::Keyboard::S] = false;
    keysDown[sf::Keyboard::D] = false;

}

InputManager::~InputManager() {

}

sf::Keyboard::Key InputManager::getKey(std::string key) {
    return keyMap.at(key);
}

void InputManager::handleKeyPressed(sf::Keyboard::Key key) {
    keyPressed = key;
    keysDown[key] = true;
}

void InputManager::handleKeyReleased(sf::Keyboard::Key key) {
    keysDown[key] = false;
    keyReleased = key;
    keyPressed = sf::Keyboard::Unknown;
}


bool InputManager::isKeyDown(std::string key) {
    return keysDown[getKey(key)];
}


bool InputManager::wasKeyPressed(std::string key) {
    if (keyPressed == getKey(key))
        return true;
    else
        return false;
}

bool InputManager::wasKeyReleased(std::string key) {
    if (keyReleased == getKey(key))
        return true;
    else
        return false;
}

