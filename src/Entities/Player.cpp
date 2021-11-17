#include "Entities/Player.h"
#include "PlayerControl.h"
using namespace Entities;

Player::Player(bool isPlayerOne):
Character(isPlayerOne? Id::player1 : Id::player2,100, 10,
          Coordinates::Vector<float>(48.f, 48.f),
          Coordinates::Vector<float>(16.f, 32.f),
          Coordinates::Vector<float>(0.f, 84.f)) {
    playerControl = new PlayerControl(this);
    isOnGround = false;
}

Player::~Player() {

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

    if (!isOnGround)
        velocity.setX(getVelocity().getX() / 1.5f);
}

void Player::jump() {
    if (isOnGround) {
        setVelocity(Coordinates::Vector<float> (0.f, -VELOCITY_Y));
        setIsOnGround(false);
    }
}

void Player::collide(Entity* pE, Coordinates::Vector<float> collision) {
    if (pE) {
        if (pE->getId() == Id::tile1 || pE->getId() == Id::tile2 || pE->getId() == Id::tile3 || pE->getId() == Id::tile4) {
            if (collision.getX() > collision.getY()) {
                if (getPosition().getY() > pE->getPosition().getY())
                    setPosition(Coordinates::Vector<float>(getPosition().getX(), getPosition().getY() + collision.getY()));
                else
                    setPosition(Coordinates::Vector<float>(getPosition().getX(), getPosition().getY() - collision.getY()));
                setIsOnGround(true);
            }
            else {
                if (getPosition().getX() < pE->getPosition().getX())
                    setPosition(Coordinates::Vector<float>(getPosition().getX() - collision.getX(), getPosition().getY()));
                else
                    setPosition(Coordinates::Vector<float>(getPosition().getX() + collision.getX(), getPosition().getY()));
            }
        }
        else
            setIsOnGround(false);
    }

}


void Player::update(float dt) {
    playerControl->notify();

    if (isWalking) {
        sprite->animationUpdate(1, isFacingLeft, dt);
    } else {
        sprite->animationUpdate(0, isFacingLeft, dt);
        velocity.setX(velocity.getX() * 0.992f);
    }

    if (!isOnGround) {
        velocity.setY(velocity.getY() + (GRAVITY * dt));
    }
    else {
        velocity.setY(0.f);
        setIsOnGround(false);
    }


    setPosition(Coordinates::Vector<float>(getPosition().getX() + getVelocity().getX()*dt,
                                           getPosition().getY() + getVelocity().getY()*dt));
    sprite->changePosition(position);
    sprite->centerViewHere();
}