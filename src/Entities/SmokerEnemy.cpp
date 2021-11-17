#include "Entities/SmokerEnemy.h"
using namespace Entities;

#include "Id.h"

SmokerEnemy::SmokerEnemy(Coordinates::Vector<float> pos)
    : Enemy(Id::enemy1, 20, 5, Coordinates::Vector<float>(48.f, 48.f), Coordinates::Vector<float>(16.f, 32.f), pos, 120.0) {}

SmokerEnemy::~SmokerEnemy() = default;

void SmokerEnemy::walk() {

    if (target->getPosition().getX() - this->getPosition().getX() >= 0){
        velocity.setX(0.025);
        setIsFacingLeft(false);
    }
    else {
        velocity.setX(-0.025);
        setIsFacingLeft(true);
    }

    setIsWalking(true);
}

void SmokerEnemy::idle(){
    setIsWalking(false);


}

void SmokerEnemy::collide(Entity* pE, Coordinates::Vector<float> collision) {
    if (pE) {
        if (pE->getId() == Id::tile1Bottom || pE->getId() == Id::tile2Bottom) {
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

    (isCommitted) ? walk(): idle();

    if (isWalking) {
        sprite->animationUpdate(2, isFacingLeft, dt);
    }
    else {
        sprite->animationUpdate(0, isFacingLeft, dt);
        velocity.setX(velocity.getX() * 0.1f);
    }

    if (!isOnGround)
        velocity.setY(getVelocity().getY() + (GRAVITY * dt));
    else
        velocity.setY(0.f);

    setPosition(Coordinates::Vector<float>(getPosition().getX() + getVelocity().getX(), getPosition().getY() + getVelocity().getY()));
    sprite->changePosition(position);
}
