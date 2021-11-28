#include "Entities/Player.h"
#include "PlayerControl.h"
using namespace Entities;
#include <iostream>

Player::Player(bool isPlayerOne):
    Character(isPlayerOne? Id::player1 : Id::player2,1000, 7,
    Coordinates::Vector<float>(16.f, 32.f),
    Coordinates::Vector<float>(150.f, 950.f)) {
    enemyNearby = NULL;
    attackTimer = 0.f;
    playerControl = new PlayerControl(this);
    initializeSprite();
}

Player::~Player() {

}

void Player::walk(bool left) {
    setIsWalking(true);

    if (left) {
        velocity.setX(-VELOCITY_X * velocityCoefficient);
        setIsFacingLeft(true);
    }


    else {
        velocity.setX(VELOCITY_X * velocityCoefficient);
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

    int flag = 0;

    if (attackTimer < 0.5f) {
        attackTimer = attackTimer + 0.01;
        if(attackTimer > 0.2f)
            isAttacking = true;
    } else {
        if (isAttacking && attackTimer > 0.5f)
            flag = 1;

        //std::cout << "Player Deu dano!" << "   Vida inimigo: " << pChar->getLife() << std::endl;
        isAttacking = false;
        attackTimer = 0.f;
    }
    //Entities::Character* pC1 = static_cast<Entities::Character*>(pE1);
    //pC2->attack(pC1);
    //std::cout << "Player Deu dano!" << std::endl << " Vida player: " << pC1->getLife() << std::endl;Entities::Character* pC2 = static_cast<Entities::Character*>(pE2);
    //        if (pC2->getAttackTimer() < 0.5f) {
    //            pC2->setAttackTimer(pC2->getAttackTimer() + 0.01);
    //            if(pC2->getAttackTimer() > 0.2f)
    //                pC2->setIsAttacking(true);
    //        } else {
    //            Entities::Character* pC1 = static_cast<Entities::Character*>(pE1);
    //            if (pC2->getIsAttacking() && pC2->getAttackTimer() > 0.5f)
    //                pC2->attack(pC1);
    //            std::cout << "Player Deu dano!" << "   Vida inimigo: " << pC1->getLife() << std::endl;
    //            pC2->setIsAttacking(false);
    //            pC2->setAttackTimer(0.f);
    //        }
    //            //Entities::Character* pC1 = static_cast<Entities::Character*>(pE1);
    //            //pC2->attack(pC1);
    //            //std::cout << "Player Deu dano!" << std::endl << " Vida player: " << pC1->getLife() << std::endl;
    if(pChar && flag) {
        if ((pChar->getLife() - damage) > 0) {
            pChar->setLife(pChar->getLife() - damage);
            std::cout << "aaaPlayer deu dano!   Vida inimigo: " << pChar->getLife() << std::endl;
        }
    }

    setIsAttacking(false);
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

void Player::saveEntity(std::ofstream& out) const{
    saveEntityInfo(out);
    out <<
        getVelocity().getX() << " " <<
        getVelocity().getY() << " " <<
        isFacingLeft << " " <<
        life << "\n";
}

void Player::setEnemyNearby(Character* enemy) {
    if(enemy)
        enemyNearby = enemy;
}

Character* Player::getEnemyNearby() {
    return enemyNearby;
}

void Player::update(float dt) {
    playerControl->notify();

//    Entities::Character* pC2 = static_cast<Entities::Character*>(pE2);
//    if (pC2->getAttackTimer() < 0.5f) {
//        pC2->setAttackTimer(pC2->getAttackTimer() + 0.01);
//        if(pC2->getAttackTimer() > 0.2f)
//            pC2->setIsAttacking(true);
//    } else {
//        Entities::Character* pC1 = static_cast<Entities::Character*>(pE1);
//        if (pC2->getIsAttacking() && pC2->getAttackTimer() > 0.5f)
//            pC2->attack(pC1);
//        std::cout << "Player Deu dano!" << "   Vida inimigo: " << pC1->getLife() << std::endl;
//        pC2->setIsAttacking(false);
//        pC2->setAttackTimer(0.f);
//    }

    //Entities::Character* pC1 = static_cast<Entities::Character*>(pE1);
    //pC2->attack(pC1);
    //std::cout << "Player Deu dano!" << std::endl << " Vida player: " << pC1->getLife() << std::endl;Entities::Character* pC2 = static_cast<Entities::Character*>(pE2);
    //        if (pC2->getAttackTimer() < 0.5f) {
    //            pC2->setAttackTimer(pC2->getAttackTimer() + 0.01);
    //            if(pC2->getAttackTimer() > 0.2f)
    //                pC2->setIsAttacking(true);
    //        } else {
    //            Entities::Character* pC1 = static_cast<Entities::Character*>(pE1);
    //            if (pC2->getIsAttacking() && pC2->getAttackTimer() > 0.5f)
    //                pC2->attack(pC1);
    //            std::cout << "Player Deu dano!" << "   Vida inimigo: " << pC1->getLife() << std::endl;
    //            pC2->setIsAttacking(false);
    //            pC2->setAttackTimer(0.f);
    //        }
    //            //Entities::Character* pC1 = static_cast<Entities::Character*>(pE1);
    //            //pC2->attack(pC1);
    //            //std::cout << "Player Deu dano!" << std::endl << " Vida player: " << pC1->getLife() << std::endl;

    enemyNearby = NULL;

    if (isAttacking && isWalking) {
        sprite->animationUpdate(3, isFacingLeft, dt);
    }
    else if(isWalking){
        sprite->animationUpdate(1, isFacingLeft, dt);
    }
    else if(isAttacking && !isWalking){
        sprite->animationUpdate(2, isFacingLeft, dt);
        velocity.setX(velocity.getX() * 0.93f);
    }
    else {
        sprite->animationUpdate(0, isFacingLeft, dt);
        velocity.setX(velocity.getX() * 0.93f);
    }

    if (!isOnGround) {
        velocity.setY(velocity.getY() + (GRAVITY * dt));
    }
    else {
        velocity.setY(0.f);
        setIsOnGround(false);
    }

    if (getPosition().getY() > 1500.f)
        neutralize();

    setIsAttacking(false);

    setPosition(Coordinates::Vector<float>(getPosition().getX() + getVelocity().getX()*dt,
                                           getPosition().getY() + getVelocity().getY()*dt));
    sprite->changePosition(position);
    sprite->centerViewHere();
}

void Player::reset() {
    isAlive = true;
    setLife(1000);
    setPosition(Coordinates::Vector<float>(150.f, 950.f));
}


