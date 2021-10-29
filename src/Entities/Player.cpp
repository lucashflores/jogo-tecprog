#include "Entities/Player.h"
using namespace Entities;

Player::Player(sf::RectangleShape shape, sf::Texture *text, sf::Vector2f pos, sf::Vector2f v): Entity(shape, text, pos, v) {
    animation = new Animation(texture, &body, sf::Vector2u(4, 1), 0.2f);
    controls.push_back(sf::Keyboard::W);
    controls.push_back(sf::Keyboard::A);
    controls.push_back(sf::Keyboard::D);
    controls.push_back(sf::Keyboard::S);
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

bool Player::isWalking() {
    for (auto it = controls.begin(); it != controls.end(); ++it) {
        if (pInputManager->isKeyDown(*it)) {

            return true;
        }
    }
    return false;
}

bool Player::isFacingLeft() {
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

}