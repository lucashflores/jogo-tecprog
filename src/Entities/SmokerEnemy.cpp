#include "Entities/SmokerEnemy.h"
using namespace Entities;
#include "Id.h"
#include <iostream>

SmokerEnemy::SmokerEnemy(Coordinates::Vector<float> pos) : Enemy(Id::smoker, 20, 5, Coordinates::Vector<float>(16.f, 32.f), pos, 120.0) {
    initializeSprite();
}

SmokerEnemy::~SmokerEnemy() = default;

void SmokerEnemy::walk(float dt) {

    if (target->getPosition().getX() - this->getPosition().getX() >= 0){
        velocity.setX(45.f);
        setIsFacingLeft(false);
    }
    else {
        velocity.setX(-45.0f);
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
        Entities::Smoke* smoke = new Entities::Smoke(position- Coordinates::Vector<float>(offset,0.f));
        smokerEntityList->addEntity(smoke);
        std::cout << "Fumaceou" << std::endl << " Vida player: " << pChar->getLife() << std::endl;
    } else {
        pChar->eliminate();
        std::cout << "Player Eliminado" << std::endl;
    }

    attackTimer = 0;
}

void SmokerEnemy::setEntityList(EntityList* EL) {
    if(EL)
        smokerEntityList = EL;
}


void SmokerEnemy::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(6, 3);
    Coordinates::Vector<float> size= Coordinates::Vector<float>(48.f, 48.f);
    sprite = new Animation(SMOKER_TEXTURE_PATH, size, imageCnt,0.25f);
    sprite->changePosition(position);
}

void SmokerEnemy::update(float dt){

    chooseTarget();

    // Vai ficar andando ou parado? Seta o movimento que vai fazer
    (isCommitted) ? walk(dt): idle();

    // Vai morder?
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


    setPosition(Coordinates::Vector<float>(getPosition().getX() + getVelocity().getX()*dt, getPosition().getY() + getVelocity().getY()*dt));
    sprite->changePosition(position);
}

void SmokerEnemy::saveEntity(std::ofstream& out) const{
    saveEntityInfo(out);

    out <<
    getVelocity().getX() << " " <<
    getVelocity().getY() << " " <<
    isFacingLeft<< " " <<
    life;
}
