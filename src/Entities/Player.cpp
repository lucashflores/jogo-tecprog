#include "Entities/Player.h"
#include "PlayerControl.h"
using namespace Entities;

Player::Player(bool isPlayerOne):
Character(isPlayerOne? Id::player1 : Id::player2,100, 10,
          Coordinates::VectorFloat(48.f, 48.f),
          Coordinates::VectorFloat(16.f, 32.f),
          Coordinates::VectorFloat(0.f, 0.f)) {
    playerControl = new PlayerControl(this);
    isOnGround = false;
}

Player::~Player() {

}

void Player::setIsOnGround(bool iOG) {
    isOnGround = iOG;
}

const bool Player::getIsOnGround() const {
    return isOnGround;
}

void Player::walk(bool left) {
    setIsWalking(true);

    if (left) {
        velocity.setX(-VELOCITY_X);
        setIsFacingLeft(true);
    }


    else {
        velocity.setX(VELOCITY_X);
        setIsFacingLeft(false);
    }
}

void Player::jump() {
    if (isOnGround) {
        setVelocity(Coordinates::VectorFloat (0.f, -VELOCITY_Y));
        setIsOnGround(false);
    }
}

void Player::collide(Entity* pE) {
    if (pE) {
        if (pE->getId() == Id::tile1) {
        }
        else
            setIsOnGround(false);

    }
}


void Player::update(float dt) {
    playerControl->notify();

    if (isWalking) {
        sprite->animationUpdate(1, isFacingLeft, dt);
    }
    else {
        sprite->animationUpdate(0, isFacingLeft, dt);
        velocity.setX(velocity.getX() * 0.8f);
    }


    Coordinates::VectorFloat pos = Coordinates::VectorFloat(position.getX() + velocity.getX(), position.getY() + velocity.getY());
    position = sprite->changePosition(pos);
    sprite->centerViewHere();
}