#include "Entities/Player.h"
using namespace Entities;

Player::Player(bool isPlayerOne): Character(100, 10, sf::Vector2f(VELOCITY_X, VELOCITY_Y)) {
    if (isPlayerOne) {
        texture = pGraphicM->loadTexture(PLAYER1_IDLE_TEXTURE);
        body.setTexture(texture);
        body.setTextureRect(sf::IntRect (0, 0, 48 ,48));
        controls.push_back(sf::Keyboard::A);
        controls.push_back(sf::Keyboard::S);
        controls.push_back(sf::Keyboard::W);
        controls.push_back(sf::Keyboard::D);
    }

}

Player::~Player() {
    pInputManager = NULL;
    if (animation)
        delete animation;
    if (animationl)
        delete animationl;
}

void Player::setInputManager(Managers::InputManager *pIM) {
    if (pIM)
        pInputManager = pIM;
}

void Player::setAnimation() {
    animation = new Animation(pGraphicM->loadTexture(PLAYER1_RUNNING_TEXTURE_PATH), &body, sf::Vector2u(6, 1), 0.2f);
    animationl = new Animation(pGraphicM->loadTexture(PLAYER1_RUNNING_LEFT_TEXTURE_PATH), &body, sf::Vector2u(6, 1), 0.2f);
    animation->setGraphicManager(pGraphicM);
    animationl->setGraphicManager(pGraphicM);
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
    if (pInputManager->getKeyPressed() == sf::Keyboard::A)
        return true;
    else
        return false;
}

void Player::move() {
    if (pInputManager->isKeyDown(controls[0]))
        body.move(sf::Vector2f(-velocity.x, 0.f));
    else if (pInputManager->isKeyDown(controls[1]))
        body.move(sf::Vector2f(0.f, velocity.x));
    else if (pInputManager->isKeyDown(controls[2]))
        body.move(sf::Vector2f(0.f, -velocity.x));
    else if (pInputManager->isKeyDown(controls[3]))
        body.move(sf::Vector2f(velocity.x, 0.f));

    position = body.getPosition();
}

void Player::update(float dt) {
    body.setTexture(texture);

    if (isFacingLeft()) {
        if (isWalking())
            animationl->animationUpdate(dt);
        else
            body.setTextureRect(sf::IntRect(48, 0, 48, 48));
    }
    else {
        if (isWalking())
            animation->animationUpdate(dt);
        else
            body.setTextureRect(sf::IntRect(0, 0, 48, 48));
    }

    pGraphicM->render(&body);
    move();
    pGraphicM->centerView(getPosition());
}