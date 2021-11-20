#include "Entities/DogEnemy.h"
using namespace Entities;

#include "Id.h"
#include <iostream>

DogEnemy::DogEnemy(Coordinates::Vector<float> pos)
    : Enemy(Id::dog, 20, 5, Coordinates::Vector<float>(23.0f, 23.0f), pos, 270.0) {
    initializeSprite();
    attackTimer = 0;
    isAttacking = false;
}

DogEnemy::~DogEnemy() = default;

void DogEnemy::walk(float dt) {

    if (target->getPosition().getX() - this->getPosition().getX() >= 0){
        if(isFacingLeft){
            if(getVelocity().getX() < 0)
                velocity.setX(getVelocity().getX() + DOG_CHANGEDIRECTIONDRAGRATE * dt);
            else
                velocity.setX(0);
        }
        if(getVelocity().getX() < DOG_TERMINALVELOCITY)
            velocity.setX(getVelocity().getX() + DOG_ACCELERATION * dt );
        else
            velocity.setX(DOG_TERMINALVELOCITY);
        setIsFacingLeft(false);
    }
    else {
        if(!isFacingLeft){
            if(getVelocity().getX() > 0)
                velocity.setX(getVelocity().getX() - DOG_CHANGEDIRECTIONDRAGRATE * dt);
            else
                velocity.setX(0);
        }
        if(getVelocity().getX() > -DOG_TERMINALVELOCITY)
            velocity.setX(getVelocity().getX() - DOG_ACCELERATION * dt );
        else
            velocity.setX(-DOG_TERMINALVELOCITY);
        setIsFacingLeft(true);
    }

    setIsWalking(true);
}

void DogEnemy::idle(float dt){

    setIsWalking(false);
}

void DogEnemy::attack(Character* pChar) {

    if ((pChar->getLife() - damage) > 0) {
        pChar->setLife(pChar->getLife() - damage);
        std::cout << "Deu dano!" << std::endl << " Vida player: " << pChar->getLife() << std::endl;
    } else {
        pChar->eliminate();
        std::cout << "Player Eliminado" << std::endl;
    }
}

void DogEnemy::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(6, 5);
    Coordinates::Vector<float> size = Coordinates::Vector<float>(40.f, 40.f);
    sprite = new Animation(DOG_TEXTURE_PATH, size, imageCnt,0.10f);
    sprite->changePosition(position);
}

void DogEnemy::update(float dt){

    chooseTarget();

    // Vai ficar andando ou parado? Seta o movimento que vai fazer
    (isCommitted) ? walk(dt): idle(dt);

    // Vai morder?
    if (getTargetDist() < 30.f && attackTimer < 1.2f) {
        attackTimer = attackTimer + dt;
        if(attackTimer > 0.2f)
            setIsAttacking(true);
    } else {
        if(isAttacking && attackTimer > 1.2f) attack(target);

        setIsAttacking(false);
        attackTimer = 0;
    }


    if (isAttacking) {
        sprite->animationUpdate(1, isFacingLeft, dt);
    }
    else if(isWalking) {
        sprite->animationUpdate(4, isFacingLeft, dt);
    }
    else {
        sprite->animationUpdate(0, isFacingLeft, dt);
        velocity.setX(velocity.getX() * DOG_STOPDRAGRATE);
    }

    if (!isOnGround)
        velocity.setY(getVelocity().getY() + (GRAVITY * dt));
    else {
        velocity.setY(0.f);
        setIsOnGround(false);
    }


    setPosition(Coordinates::Vector<float>(getPosition().getX() + getVelocity().getX()*dt, getPosition().getY() + getVelocity().getY()*dt));
    sprite->changePosition(position);
}