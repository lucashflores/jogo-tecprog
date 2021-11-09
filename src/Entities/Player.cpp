#include "Entities/Player.h"
#include "PlayerControl.h"
using namespace Entities;

Player::Player(bool isPlayerOne): Character(isPlayerOne? Id::player1 : Id::player2,100, 10, sf::Vector2f(0.f, 0.f)) {
    playerControl = new PlayerControl(this);
    isOnGround = false;
    if (isPlayerOne) {
        texture = pGraphicM->loadTexture(PLAYER1_IDLE_TEXTURE);
        body.setTexture(texture);
        body.setTextureRect(sf::IntRect (0, 0, 48 ,48));
        animation = new Animation(pGraphicM->loadTexture(PLAYER1_RUNNING_TEXTURE_PATH), &body, sf::Vector2u(6, 1), 0.2f);
    }
}

Player::~Player() {
    if (animation)
        delete animation;
}

void Player::setIsOnGround(bool iOG) {
    isOnGround = iOG;
}

const bool Player::getIsOnGround() const {
    return isOnGround;
}

void Player::walk(bool left) {
    if (left)
        velocity.x = -VELOCITY_X;
    else
       velocity.x = VELOCITY_X;
    if (!isOnGround)
        velocity.x /= 1.5f;
}

void Player::jump() {
    if (isOnGround) {
        setVelocity(sf::Vector2f (0.f, -VELOCITY_Y));
        setIsOnGround(false);
    }
}

sf::FloatRect Player::getHitBox() {
    sf::FloatRect rect = body.getGlobalBounds();
    /*
    rect.top -= 16.f;
    rect.width -= 16.f;
    rect.height = 32.f;
     */
    return rect;
}

void Player::collide(Entity* pE) {
    if (pE) {
        if (pE->getId() == Id::obstacle) {
            if (((pE->getHitBox().top - 24.f) - getPosition().y) < (getPosition().y - (pE->getHitBox().top + 8.f)))
                setPosition(sf::Vector2f(getPosition().x, pE->getHitBox().top - 24.f));
            else {
                setPosition(sf::Vector2f(getPosition().x, pE->getHitBox().top + 8.f));
                velocity.y = 0;
            }

            setIsOnGround(true);

            /*
            else if (getPosition().y >= (pE->getHitBox().top - 12.f)) {
                move(sf::Vector2f(0.f, VELOCITY_Y));
                setIsOnGround(false);
            }
            */


            /*
            else {
                if (isFacingLeft)
                    setPosition(sf::Vector2f(pE->getHitBox().left + pE->getHitBox().width, getPosition().y));
                else
                    setPosition(sf::Vector2f(pE->getHitBox().left - 16.f, getPosition().y));
            }
            */

        }
        else
            setIsOnGround(false);

    }
}

void Player::update(float dt) {
    body.setTexture(texture);
    if (isWalking)
        animation->animationUpdate(dt);
    else {
        body.setTextureRect(sf::IntRect(0, 0, 48, 48));
        velocity.x = 0.f;
    }

    if (!isOnGround) {
        velocity.y += GRAVITY * dt;
    }


    if (isFacingLeft)
        body.setScale(-1, 1);
    else
        body.setScale(1, 1);

    playerControl->notify();
    move(sf::Vector2f(velocity.x, velocity.y + (GRAVITY*dt)));
    pGraphicM->centerView(getPosition());
}