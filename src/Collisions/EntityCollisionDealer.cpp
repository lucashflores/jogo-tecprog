#include "Collisions/EntityCollisionDealer.h"
using namespace Collisions;

EntityCollisionDealer::EntityCollisionDealer() {}

EntityCollisionDealer::~EntityCollisionDealer() {}

void EntityCollisionDealer::playerCollision(Entities::Entity *pE1, Entities::Entity *pE2, Coordinates::Vector<float> collision) {
    if (pE1->getPosition().getX() > pE2->getPosition().getX())
        pE1->setPosition(Coordinates::Vector<float>(pE1->getPosition().getX() + collision.getX(), pE1->getPosition().getY()));

    else
        pE1->setPosition(Coordinates::Vector<float>(pE1->getPosition().getX() - collision.getX(), pE1->getPosition().getY()));

    if (pE1->getId() == Id::projectile)
        pE1->eliminate();
}

void EntityCollisionDealer::enemyCollision(Entities::Entity *pE1, Entities::Entity *pE2,
                                      Coordinates::Vector<float> collision) {
    if (pE1->getPosition().getX() > pE2->getPosition().getX())
        pE1->setPosition(Coordinates::Vector<float>(pE1->getPosition().getX() + collision.getX(), pE1->getPosition().getY()));

    else
        pE1->setPosition(Coordinates::Vector<float>(pE1->getPosition().getX() - collision.getX(), pE1->getPosition().getY()));

}

void EntityCollisionDealer::projectileCollision(Entities::Entity *pE1, Entities::Entity *pE2,
                                           Coordinates::Vector<float> collision) {
    Entities::Character* pC1 =  static_cast<Entities::Character*>(pE1);
    pC1->setLife(pC1->getLife() - pE2->getDamage());
}