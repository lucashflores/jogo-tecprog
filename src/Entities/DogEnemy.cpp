#include "Entities/DogEnemy.h"
using namespace Entities;

#include "Id.h"
#include <iostream>

DogEnemy::DogEnemy(Coordinates::Vector<float> pos)
    : Enemy(Id::enemy2, 20, 5, Coordinates::Vector<float>(23.0f, 23.0f), pos, 270.0) {
    initializeSprite();
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

void DogEnemy::idle(){

    setIsWalking(false);
}

void DogEnemy::attack(Character* pChar) {

    if((pChar->getLife() - damage) > 0) {
        pChar->setLife(pChar->getLife() - damage);
        //std::cout << "Deu dano!" << std::endl << " Vida player: " << pChar->getLife() << std::endl;
    }
    else {
        pChar->eliminate();
        //std::cout << "Player Eliminado" << std::endl;
    }
}

void DogEnemy::collide(Entity* pE, Coordinates::Vector<float> collision) {
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
        if (pE->getId() == Id::player1 || pE->getId() == Id::player2) {
            attack(dynamic_cast<Character*>(pE));
            isAttacking = true;
        }
    }
}

void DogEnemy::update(float dt){

    chooseTarget();

    (isCommitted) ? walk(dt): idle();

    if (isWalking) {
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

void DogEnemy::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(6, 5);
    Coordinates::Vector<float> size = Coordinates::Vector<float>(40.f, 40.f);
    sprite = new Animation(ENEMY2_TEXTURE_PATH, size, imageCnt,0.10f);
    sprite->changePosition(position);
}
