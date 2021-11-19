#include "Entities/PunkBoss.h"
#include <stdlib.h>
#include "Entities/Projectile.h"

using namespace Entities;

PunkBoss::PunkBoss(Coordinates::Vector<float> pos)
    : Enemy(Id::enemy3, 20, 5, Coordinates::Vector<float>(32.0f, 64.0f), pos, 300.0) {
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
    Coordinates::Vector<float> offset = (isFacingLeft)?(Coordinates::Vector<float>(35.f,0.f)):(Coordinates::Vector<float>(-35.f,yrand- 15));
    Entities::Projectile* attackProjectile = new Entities::Projectile((position - offset), isFacingLeft);
    bossEntityList->addEntity(attackProjectile);
}

void Entities::PunkBoss::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(8, 12);
    Coordinates::Vector<float> size = Coordinates::Vector<float>(96.f, 96.f);
    sprite = new Animation(BOSS_TEXTURE_PATH, size, imageCnt,0.2f);
    sprite->changePosition(position);
}

void PunkBoss::setEntityList(EntityList* EL) {
    if(EL)
        bossEntityList = EL;
}


void Entities::PunkBoss::collide(Entity* pE, Coordinates::Vector<float> collision) {
    if (pE) {

        // If is a tile
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
        else if (pE->getId() == Id::projectile){return;}
        else
            setIsOnGround(false);

        // If is a player
        if (pE->getId() == Id::player1 || pE->getId() == Id::player2) {

        }
    }
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