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
    keyMap["B"] = sf::Keyboard::B;
    keyMap["C"] = sf::Keyboard::C;
    keyMap["D"] = sf::Keyboard::D;
    keyMap["E"] = sf::Keyboard::E;
    keyMap["F"] = sf::Keyboard::F;
    keyMap["G"] = sf::Keyboard::G;
    keyMap["H"] = sf::Keyboard::H;
    keyMap["I"] = sf::Keyboard::I;
    keyMap["J"] = sf::Keyboard::J;
    keyMap["K"] = sf::Keyboard::K;
    keyMap["L"] = sf::Keyboard::L;
    keyMap["M"] = sf::Keyboard::M;
    keyMap["N"] = sf::Keyboard::N;
    keyMap["O"] = sf::Keyboard::O;
    keyMap["P"] = sf::Keyboard::P;
    keyMap["Q"] = sf::Keyboard::Q;
    keyMap["R"] = sf::Keyboard::R;
    keyMap["S"] = sf::Keyboard::S;
    keyMap["T"] = sf::Keyboard::T;
    keyMap["U"] = sf::Keyboard::U;
    keyMap["V"] = sf::Keyboard::V;
    keyMap["W"] = sf::Keyboard::W;
    keyMap["X"] = sf::Keyboard::X;
    keyMap["Y"] = sf::Keyboard::Y;
    keyMap["Z"] = sf::Keyboard::Z;
    keyMap["1"] = sf::Keyboard::Num1;
    keyMap["2"] = sf::Keyboard::Num2;
    keyMap["3"] = sf::Keyboard::Num3;
    keyMap["4"] = sf::Keyboard::Num4;
    keyMap["5"] = sf::Keyboard::Num5;
    keyMap["6"] = sf::Keyboard::Num6;
    keyMap["7"] = sf::Keyboard::Num7;
    keyMap["8"] = sf::Keyboard::Num8;
    keyMap["9"] = sf::Keyboard::Num9;
    keyMap["0"] = sf::Keyboard::Num0;

    keyMap["Space"] = sf::Keyboard::Space;
    keyMap["Enter"] = sf::Keyboard::Enter;
    keyMap["Escape"] = sf::Keyboard::Escape;
    keyMap["BackSpace"] = sf::Keyboard::BackSpace;

    keyMap["Right"] = sf::Keyboard::Right;
    keyMap["Left"] = sf::Keyboard::Left;
    keyMap["Up"] = sf::Keyboard::Up;
    keyMap["Down"] = sf::Keyboard::Down;

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
    keyPressedInFrame = key;
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

bool InputManager::wasKeyPressedInFrame(std::string key) {
    return keyPressedInFrame == keyMap.at(key) ? true : false;
}

void InputManager::clearKeyPressedInFrame() {
    keyPressedInFrame = sf::Keyboard::Unknown;
}



