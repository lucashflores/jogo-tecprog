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

/* TODO: remover se funcionar
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
        else if (pE->getId() == Id::projectile){return;}
        else
            setIsOnGround(false);
    }
}
*/

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
        if (getTargetDist() < 30.f && attackTimer < 0.5f) {
            attackTimer += dt;
            if (attackTimer > 0.f)
                setIsAttacking(true);

<<<<<<< HEAD
        } else {
=======
    if (getTargetDist() < 55.f && attackTimer < 0.5f) {
        attackTimer += dt;
        if(attackTimer > 0.2f)
            setIsAttacking(true);
>>>>>>> 765ea23d113b3e3f487d8ce05effd29b43c74d28

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

void SmokerEnemy::saveEntity(std::ofstream& out){
    saveEntityInfo(out);

    out <<
        isFacingLeft<< " " <<
        view_range<< " " <<
        attackTimer<< " " <<
        life;
}

void SmokerEnemy::restoreEntity(std::ifstream& in) {
    try{
        restoreEntity(in);

        in >>
           isFacingLeft >>
           view_range >>
           attackTimer >>
           life;
    }

    catch (std::invalid_argument e){
        std::cerr << "Error: Could not load SmokerEnemy!" << std::endl;
    }
}
