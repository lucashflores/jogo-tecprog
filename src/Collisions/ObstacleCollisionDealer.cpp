#include "Collisions/ObstacleCollisionDealer.h"
using namespace Collisions;

ObstacleCollisionDealer::ObstacleCollisionDealer() {

}

ObstacleCollisionDealer::~ObstacleCollisionDealer() {

}

void ObstacleCollisionDealer::oilTileCollision(Entities::Entity *pE1, Entities::Entity *pE2,
                                          Coordinates::Vector<float> collision) {
    Entities::Character* pC1 =  static_cast<Entities::Character*>(pE1);

    pC1->setIsOnGround(true);
    pC1->setVelocityCoefficient(1.f);
}

void ObstacleCollisionDealer::signCollision(Entities::Entity *pE1, Entities::Entity *pE2, Coordinates::Vector<float> collision) {
    return;
}

void ObstacleCollisionDealer::barrelCollision(Entities::Entity *pE1, Entities::Entity *pE2,
                                         Coordinates::Vector<float> collision) {
    Entities::Character* pC1 =  static_cast<Entities::Character*>(pE1);

    if (collision.getX() > collision.getY()) {
            pC1->setIsOnGround(true);
            pC1->setPosition(Coordinates::Vector<float>(pC1->getPosition().getX(), pC1->getPosition().getY() - collision.getY()));
    }
    else {
        if (pC1->getPosition().getX() < pE2->getPosition().getX()) {
            pC1->setPosition(Coordinates::Vector<float>(pC1->getPosition().getX() - collision.getX(), pC1->getPosition().getY()));
        }
        else
            pC1->setPosition(Coordinates::Vector<float>(pC1->getPosition().getX() + collision.getX(), pC1->getPosition().getY()));
    }
}

void ObstacleCollisionDealer::fireCollision(Entities::Entity *pE1, Entities::Entity *pE2, Coordinates::Vector<float> collision) {

    if(pE1->getId() != Id::projectile) {
        Entities::Character* pC1 = static_cast<Entities::Character*>(pE1);
        Entities::Fire* pF2 = static_cast<Entities::Fire*>(pE2);

        if (pF2->getTimer() > 1.0f) {
            pC1->setLife(pC1->getLife() - pF2->getDamage());
            pF2->setTimer(0.f);
        }
    }

}


