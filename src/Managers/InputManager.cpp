#include "Managers/InputManager.h"
using namespace Managers;

InputManager* InputManager::instance = NULL;

InputManager *InputManager::getInstance() {
    if (instance == NULL)
        instance = new InputManager();
    return instance;
}

InputManager::InputManager() {
    keysDown[sf::Keyboard::A] = false;
    keysDown[sf::Keyboard::W] = false;
    keysDown[sf::Keyboard::S] = false;
    keysDown[sf::Keyboard::D] = false;

}

InputManager::~InputManager() {

}

void InputManager::handleKeyPressed(sf::Keyboard::Key key) {
    keyPressed = key;
    keysDown[key] = true;
}

void InputManager::handleKeyReleased(sf::Keyboard::Key key) {
    keysDown[key] = false;
    keyReleased = key;
}


bool InputManager::isKeyDown(sf::Keyboard::Key key) {
    return keysDown[key];
}


sf::Keyboard::Key InputManager::getKeyPressed() {
    return keyPressed;
}

sf::Keyboard::Key InputManager::getKeyReleased() {
    return keyReleased;
}


