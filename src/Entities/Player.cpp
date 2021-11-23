#include "Entities/Player.h"
#include "PlayerControl.h"
using namespace Entities;
#include <iostream>

Player::Player(bool isPlayerOne):
Character(isPlayerOne? Id::player1 : Id::player2,1000, 10,
          Coordinates::Vector<float>(16.f, 32.f),
          Coordinates::Vector<float>(150.f, 950.f)) {
    playerControl = new PlayerControl(this);
    isOnGround = false;
    initializeSprite();
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

void Player::attack(Character* pChar) {
    if ((pChar->getLife() - damage) > 0) {
        pChar->setLife(pChar->getLife() - damage);
        std::cout << "Deu dano!" << std::endl << " Vida inimigo: " << pChar->getLife() << std::endl;
    } else {
        pChar->eliminate();
        std::cout << "Inimigo Eliminado" << std::endl;
    }

}

void Player::initializeSprite() {

    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(6, 8);
    Coordinates::Vector<float> size= Coordinates::Vector<float>(48.f, 48.f);

    if(getId() == Id::player1){
        sprite = new Animation(PLAYER1_TEXTURE_PATH, size, imageCnt,0.10f);
    }
    else if(getId() == Id::player2) {
        sprite = new Animation(PLAYER2_TEXTURE_PATH, size, imageCnt, 0.10f);
    }

    sprite->changePosition(position);

}

void Player::update(float dt) {
    playerControl->notify();

    if (isAttacking && isWalking) {
        sprite->animationUpdate(3, isFacingLeft, dt);
    }
    else if(isWalking){
        sprite->animationUpdate(1, isFacingLeft, dt);
        //setVelocity(Coordinates::Vector<float>(getVelocity().getX() * 0.2f, getVelocity().getY() * 0.99f));
    }
    else if(isAttacking && !isWalking){
        sprite->animationUpdate(2, isFacingLeft, dt);
        velocity.setX(velocity.getX() * 0.90f);
    }
    else {
        sprite->animationUpdate(0, isFacingLeft, dt);
        velocity.setX(velocity.getX() * 0.90f);
    }

    if (!isOnGround) {
        velocity.setY(velocity.getY() + (GRAVITY * dt));
    }
    else {
        velocity.setY(0.f);
        setIsOnGround(false);
    }

    setIsAttacking(false);

    setPosition(Coordinates::Vector<float>(getPosition().getX() + getVelocity().getX()*dt,
                                           getPosition().getY() + getVelocity().getY()*dt));
    sprite->changePosition(position);
    sprite->centerViewHere();
}

void Player::saveEntity(std::ofstream& out) {
    saveEntityInfo(out);
    out <<
        isPlayerOne << " " <<
        isFacingLeft << " " <<
        attackTimer << " " <<
        life;
}

void Player::restoreEntity(std::ifstream& in) {

    try {
        restoreEntity(in);

        in >>
            isPlayerOne >>
            isFacingLeft >>
            attackTimer >>
            life;
    }

    catch (std::invalid_argument e) {
        std::cerr << "Error: Could not load player!" << std::endl;
    }
}
