#include "Entities/SmokerEnemy.h"
using namespace Entities;

#include "Id.h"

SmokerEnemy::SmokerEnemy(Coordinates::Vector<float> pos)
    : Enemy(Id::enemy1, 20, 5, Coordinates::Vector<float>(48.f, 48.f), Coordinates::Vector<float>(16.f, 32.f), pos, 120.0) {}

SmokerEnemy::~SmokerEnemy() = default;

void SmokerEnemy::walk() {

    if (target->getPosition().getX() - this->getPosition().getX() >= 0){
        velocity.setX(0.01);
        setIsFacingLeft(false);
    }
    else {
        velocity.setX(-0.01);
        setIsFacingLeft(true);
    }

    setIsWalking(true);
}

void SmokerEnemy::idle(){
    setIsWalking(false);


}

void SmokerEnemy::collide(Entity* pE, Coordinates::Vector<float> Collision) {
    if (pE) {
        if (pE->getId() == Id::tile1) {
        }
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

    Coordinates::Vector<float> pos = Coordinates::Vector<float>(position.getX() + velocity.getX(), position.getY() + velocity.getY());
    position = sprite->changePosition(pos);
}
