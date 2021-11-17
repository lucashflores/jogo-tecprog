#include "Entities/SmokerEnemy.h"
using namespace Entities;

#include "Id.h"

SmokerEnemy::SmokerEnemy(Coordinates::Vector<float> pos) : Enemy(Id::enemy1, 20, 5, Coordinates::Vector<float>(16.f, 32.f), pos, 120.0) {
    initializeSprite();
}

SmokerEnemy::~SmokerEnemy() = default;

void SmokerEnemy::walk(float dt) {

    if (target->getPosition().getX() - this->getPosition().getX() >= 0){
        velocity.setX(25.f);
        setIsFacingLeft(false);
    }
    else {
        velocity.setX(-25.0f);
        setIsFacingLeft(true);
    }

    setIsWalking(true);
}

void SmokerEnemy::idle(){
    setIsWalking(false);


}

void SmokerEnemy::collide(Entity* pE, Coordinates::Vector<float> collision) {
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

void SmokerEnemy::update(float dt){

    chooseTarget();

    (isCommitted) ? walk(dt): idle();

    if (isWalking) {
        sprite->animationUpdate(2, isFacingLeft, dt);
    }
    else {
        sprite->animationUpdate(0, isFacingLeft, dt);
        velocity.setX(velocity.getX() * 0.99f);
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

void SmokerEnemy::attack(Character* pChar) {
    return;
}

void SmokerEnemy::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(6, 3);
    Coordinates::Vector<float> size= Coordinates::Vector<float>(48.f, 48.f);
    sprite = new Animation(ENEMY1_TEXTURE_PATH, size, imageCnt,0.25f);
    sprite->changePosition(position);}
