#include "Entities/Player.h"
using namespace Entities;

Player::Player(bool isPlayerOne): Character(100, 10, sf::Vector2f(VELOCITY_X, VELOCITY_Y)) {
    if (isPlayerOne) {
        body.setTexture(pGraphicM->loadTexture(PLAYER1_IDLE_TEXTURE));
        body.setTextureRect(sf::IntRect (0, 0, 48 ,48));
    }
    controls.push_back(sf::Keyboard::A);
    controls.push_back(sf::Keyboard::S);
    controls.push_back(sf::Keyboard::W);
    controls.push_back(sf::Keyboard::D);
    animation = NULL;
}

Player::~Player() {
    pInputManager = NULL;
    if (animation)
        delete animation;
}

void Player::setInputManager(Managers::InputManager *pIM) {
    if (pIM)
        pInputManager = pIM;
}

bool Player::isWalking() const{
    for (auto it = controls.begin(); it != controls.end(); ++it) {
        if (pInputManager->isKeyDown(*it)) {

            return true;
        }
    }
    return false;
}

bool Player::isFacingLeft() const{
    if (pInputManager->getKeyReleased() == sf::Keyboard::A)
        return true;
    else
        return false;
}

void Player::move() {
    if (pInputManager->isKeyDown(sf::Keyboard::W))
        body.move(sf::Vector2f(0.f, -velocity.x));
    else if (pInputManager->isKeyDown(sf::Keyboard::A))
        body.move(sf::Vector2f(-velocity.x, 0.f));
    else if (pInputManager->isKeyDown(sf::Keyboard::D))
        body.move(sf::Vector2f(velocity.x, 0.f));
    else if (pInputManager->isKeyDown(sf::Keyboard::S))
        body.move(sf::Vector2f(0.f, velocity.x));
    position = body.getPosition();
}

void Player::update(float dt) {
    pGraphicM->render(&body);
    move();
}