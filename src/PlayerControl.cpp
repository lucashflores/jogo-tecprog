#include "PlayerControl.h"

PlayerControl::PlayerControl(bool isPlayerOne): controls() {
    pInputManager = Managers::InputManager::getInstance();
    if (isPlayerOne) {
        controls["left"] = sf::Keyboard::A;
        controls["right"] = sf::Keyboard::D;
        controls["up"] = sf::Keyboard::W;
        controls["down"] = sf::Keyboard::S;
    }
}

PlayerControl::~PlayerControl() {
    pInputManager = NULL;
}

const bool PlayerControl::isPlayerWalking() {
    for (auto it = controls.begin(); it != controls.end(); ++it) {
        if (pInputManager->isKeyDown(it->second)) {
            return true;
        }
    }
    return false;
}

const bool PlayerControl::isPlayerFacingLeft() {
    if (pInputManager->isKeyDown(controls.at("left")) && !pInputManager->isKeyDown(controls.at("right")))
        return true;
    else if (pInputManager->isKeyDown(controls.at("right")) && !pInputManager->isKeyDown(controls.at("left")))
        return false;
    else {
        if (pInputManager->getKeyPressed() == controls.at("left"))
            return true;
        else
            return false;
    }
}

void PlayerControl::movePlayer(Entities::Player* player) {
    if (pInputManager->isKeyDown(controls.at("left")))
        player->setVelocity(sf::Vector2f(-VELOCITY_X, 0.f));
    else if (pInputManager->isKeyDown(controls.at("up")))
        player->setVelocity(sf::Vector2f(0.f, -VELOCITY_X));
    else if (pInputManager->isKeyDown(controls.at("right")))
        player->setVelocity(sf::Vector2f(VELOCITY_X, 0.f));
    else if (pInputManager->isKeyDown(controls.at("down")))
        player->setVelocity(sf::Vector2f(0.f, VELOCITY_X));
    else
        player->setVelocity(sf::Vector2f(0.f, 0.f));
}