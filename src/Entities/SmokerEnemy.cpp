#include "Entities/SmokerEnemy.h"
using namespace Entities;
#include "Id.h"
#include <iostream>

SmokerEnemy::SmokerEnemy(Coordinates::Vector<float> pos):
    Enemy(Id::smoker, 15, 2, Coordinates::Vector<float>(16.f, 32.f), pos, 120.0) {

    initializeSprite();
    projectileMaker = NULL;
}

SmokerEnemy::~SmokerEnemy() { };

void SmokerEnemy::walk(float dt) {

    if (target->getPosition().getX() - this->getPosition().getX() >= 0){
        velocity.setX(45.f * velocityCoefficient);
        setIsFacingLeft(false);
    }
    else {
        velocity.setX(-45.0f * velocityCoefficient);
        setIsFacingLeft(true);
    }

    setIsWalking(true);
}

void SmokerEnemy::idle(){
    setIsWalking(false);
}

void SmokerEnemy::attack(Character* pChar) {

    if ((pChar->getLife() - damage) > 0) {
        //pChar->setLife(pChar->getLife() - damage);
        float offset = 25;
        (isFacingLeft)?(offset=offset):(offset=-offset);
        if (projectileMaker) {
            projectileMaker->makeSmoke(position - Coordinates::Vector<float>(offset,0.f));
        }
        //std::cout << "Fumaceou" << std::endl << " Vida player: " << pChar->getLife() << std::endl;
    } else {
        pChar->neutralize();
        std::cout << "Player Eliminado" << std::endl;
    }

    attackTimer = 0;
}

void SmokerEnemy::setProjectileMaker(Stages::ProjectileMaker* pPM) {
    if(pPM)
        projectileMaker = pPM;
}


void SmokerEnemy::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(6, 3);
    Coordinates::Vector<float> size= Coordinates::Vector<float>(48.f, 48.f);
    sprite = new Animation(SMOKER_TEXTURE_PATH, size, imageCnt,0.25f);
    sprite->changePosition(position);
}

void SmokerEnemy::update(float dt){

    chooseTarget();

    (isCommitted) ? walk(dt): idle();

    if (target) {
        if (getTargetDist() < 55.f && attackTimer < 0.5f) {
            attackTimer += dt;
            if(attackTimer > 0.2f)
                setIsAttacking(true);
        } else {
            if (isAttacking && attackTimer > 0.5f) attack(target);
            setIsAttacking(false);
            attackTimer = 0;
        }
    }

    if (isAttacking) {
        sprite->animationUpdate(1, isFacingLeft, dt);
    }
    else if(isWalking) {
        sprite->animationUpdate(2, isFacingLeft, dt);
    }
    else {
        sprite->animationUpdate(0, isFacingLeft, dt);
        velocity.setX(velocity.getX() * 0.996f);
    }

    if (!isOnGround)
        velocity.setY(getVelocity().getY() + (GRAVITY * dt));
    else {
        velocity.setY(0.f);
        setIsOnGround(false);
    }

    if (getPosition().getY() > 1500.f)
        neutralize();


    setPosition(Coordinates::Vector<float>(getPosition().getX() + getVelocity().getX()*dt, getPosition().getY() + getVelocity().getY()*dt));
    sprite->changePosition(position);
}

void SmokerEnemy::saveEntity(std::ofstream& out) const{
    saveEntityInfo(out);

    out <<
    getVelocity().getX() << " " <<
    getVelocity().getY() << " " <<
    isFacingLeft<< " " <<
    life << "\n";
}
