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
    pC1->setVelocity(Coordinates::Vector<float>(pC1->getVelocity().getX() * 0.1f, pC1->getVelocity().getY() * 0.991f));
    pC1->setPosition(Coordinates::Vector<float>(pC1->getPosition().getX(), pC1->getPosition().getY() - collision.getY()));
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
    Entities::Character* pC1 =  static_cast<Entities::Character*>(pE1);
    Entities::Obstacle* pO1 =  static_cast<Entities::Obstacle*>(pE2);
    pC1->setLife(pC1->getLife() - pO1->getDamage());
}


