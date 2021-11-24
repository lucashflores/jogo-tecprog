#include "Entities/PunkBoss.h"
#include <stdlib.h>
#include "Entities/Projectile.h"

using namespace Entities;

PunkBoss::PunkBoss(Coordinates::Vector<float> pos)
    : Enemy(Id::punk, 20, 5, Coordinates::Vector<float>(32.0f, 64.0f), pos, 600.0) {
    initializeSprite();
    attackTimer = 0;
    isAttacking = false;
}

PunkBoss::~PunkBoss() {

}

void Entities::PunkBoss::idle(float dt) {
    if (target->getPosition().getX() - this->getPosition().getX() >= 0){
        setIsFacingLeft(false);
    }
    else
        setIsFacingLeft(true);
}

void Entities::PunkBoss::attack(Character* pChar) {

    srand(time(NULL));
    float yrand = rand() % 30;
    Coordinates::Vector<float> offset = (this->isFacingLeft)?(Coordinates::Vector<float>(35.f,0.f)):(Coordinates::Vector<float>(-35.f,yrand- 15));
    Entities::Projectile* attackProjectile = new Entities::Projectile((this->position - offset), this->isFacingLeft);
    this->bossEntityList->addEntity(attackProjectile);
}

void Entities::PunkBoss::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(8, 12);
    Coordinates::Vector<float> size = Coordinates::Vector<float>(96.f, 96.f);
    sprite = new Animation(PUNK_TEXTURE_PATH, size, imageCnt,0.2f);
    sprite->changePosition(position);
}

void PunkBoss::setEntityList(EntityList* EL) {
    if(EL)
        bossEntityList = EL;
}


void Entities::PunkBoss::update(float dt) {

    chooseTarget();

    // Vai ficar andando ou parado? Seta o movimento que vai fazer
    (isCommitted) ? idle(dt) : idle(dt);

    //attack(target);

    /* Vai morder?

    if (getTargetDist() < view_range) {
        if (attackTimer < 1.2f){
            attackTimer = attackTimer + dt;
            setIsAttacking(true);
        }
    } else {
        if(isAttacking) attack(target);
        setIsAttacking(false);
        attackTimer = 0;
    }
    //*/

    //
    if (getTargetDist() < view_range && attackTimer < 1.8f) {
        attackTimer = attackTimer + dt;
        if(attackTimer > 0.2f)
            setIsAttacking(true);
    } else {
        if(isAttacking && attackTimer > 1.2f) attack(target);
        setIsAttacking(false);
        attackTimer = 0;
    }
    //*/


    if (isAttacking) {
        sprite->animationUpdate(2, isFacingLeft, dt);
    }
    else if(isWalking) {
        sprite->animationUpdate(10, isFacingLeft, dt);
    }
    else {
        sprite->animationUpdate(7, isFacingLeft, dt);
        velocity.setX(velocity.getX() * 0.2f);
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

void PunkBoss::saveEntity(std::ofstream& out) const{
    saveEntityInfo(out);

    out <<
    getVelocity().getX() << " " <<
    getVelocity().getY() << " " <<
    isFacingLeft<< " " <<
    life;
}