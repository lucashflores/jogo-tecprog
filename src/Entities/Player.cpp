#include "Entities/Player.h"
#include "PlayerControl.h"
using namespace Entities;

Player::Player(bool isPlayerOne): Character(isPlayerOne? Id::player1 : Id::player2,100, 10, sf::Vector2f(0.f, 0.f)) {
    playerControl = new PlayerControl(isPlayerOne);
    if (isPlayerOne) {
        texture = pGraphicM->loadTexture(PLAYER1_IDLE_TEXTURE);
        body.setTexture(texture);
        body.setTextureRect(sf::IntRect (0, 0, 48 ,48));
    }
    setAnimation();
}

Player::~Player() {
    if (animation)
        delete animation;
    if (animationl)
        delete animationl;
}


void Player::setAnimation() {
    animation = new Animation(pGraphicM->loadTexture(PLAYER1_RUNNING_TEXTURE_PATH), &body, sf::Vector2u(6, 1), 0.2f);
    animationl = new Animation(pGraphicM->loadTexture(PLAYER1_RUNNING_LEFT_TEXTURE_PATH), &body, sf::Vector2u(6, 1), 0.2f);
    animation->setGraphicManager(pGraphicM);
    animationl->setGraphicManager(pGraphicM);
}

bool Player::isWalking() const{
    return playerControl->isPlayerWalking();
}

bool Player::isFacingLeft() const{
    return playerControl->isPlayerFacingLeft();
}

void Player::setIsOnGround(bool isOnGround) {
    isPlayerOnGround = isOnGround;
}

const bool Player::getIsOnGround() const {
    return isPlayerOnGround;
}

void Player::collide(Entity* pE) {
    if (pE) {
        if (pE->getId() == Id::obstacle) {
            setPosition(sf::Vector2f(getPosition().x, pE->getHitBox().top - 48.f));
        }

    }
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

    playerControl->movePlayer(this);
    move(velocity);
    //move(sf::Vector2f(0.f, velocity.y + (GRAVITY * dt)));
    pGraphicM->centerView(getPosition());
}