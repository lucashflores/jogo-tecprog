#include "Entities/Player.h"
#include "PlayerControl.h"
using namespace Entities;

Player::Player(bool isPlayerOne):
Character(isPlayerOne? Id::player1 : Id::player2,100, 10,
          Coordinates::Vector<float>(48.f, 48.f),
          Coordinates::Vector<float>(16.f, 32.f),
          Coordinates::Vector<float>(0.f, 100.f)) {
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

    setVelocity(Coordinates::Vector<float> (0.f, -VELOCITY_X));

}

void Player::down() {
    setVelocity(Coordinates::Vector<float>(0.f, VELOCITY_X));
}

void Player::collide(Entity* pE, Coordinates::Vector<float> collision) {
    if (pE) {
        if (pE->getId() == Id::tile1 || pE->getId() == Id::tile2) {
            setIsOnGround(true);
            if (collision.getX() > collision.getY()) {
                if (getPosition().getY() > pE->getPosition().getY())
                    setPosition(Coordinates::Vector<float>(getPosition().getX(), getPosition().getY() + collision.getY()));
                else
                    setPosition(Coordinates::Vector<float>(getPosition().getX(), getPosition().getY() - collision.getY()));
            }
            else {
                if (getPosition().getX() < pE->getPosition().getX())
                    setPosition(Coordinates::Vector<float>(getPosition().getX() - collision.getX(), getPosition().getY()));
                else
                    setPosition(Coordinates::Vector<float>(getPosition().getX() + collision.getX(), getPosition().getY()));
            }
            //sprite->changePosition(position);
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
        velocity.setY(velocity.getY() * 0.8f);
    }


    Coordinates::Vector<float> pos = Coordinates::Vector<float>(position.getX() + velocity.getX(), position.getY() + velocity.getY());
    position = sprite->changePosition(pos);
    sprite->centerViewHere();
}