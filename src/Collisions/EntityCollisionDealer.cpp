#include "Collisions/EntityCollisionDealer.h"
using namespace Collisions;
#include <Entities/Smoke.h>
#include <Entities/Player.h>

EntityCollisionDealer::EntityCollisionDealer() {}

EntityCollisionDealer::~EntityCollisionDealer() {}

void EntityCollisionDealer::playerCollision(Entities::Entity *pE1, Entities::Entity *pE2, Coordinates::Vector<float> collision) {
    if(pE1->getId()!=Id::punk){
        if (pE1->getPosition().getX() > pE2->getPosition().getX())
            pE1->setPosition(
                    Coordinates::Vector<float>(pE1->getPosition().getX() + collision.getX(), pE1->getPosition().getY()));

        else
            pE1->setPosition(
                    Coordinates::Vector<float>(pE1->getPosition().getX() - collision.getX(), pE1->getPosition().getY()));
    }


    if (pE1->getId() == Id::projectile)
        pE1->neutralize();

    Entities::Player* pP2 = static_cast<Entities::Player*>(pE2);
    Entities::Character* pC1 = static_cast<Entities::Character*>(pE1);
    pP2->setEnemyNearby(pC1);

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

void EntityCollisionDealer::smokeCollision(Entities::Entity *pE1, Entities::Entity *pE2,
                                           Coordinates::Vector<float> collision) {
    Entities::Smoke* pS2 = static_cast < Entities::Smoke*>(pE2);
    if (pS2->getCooldown() < 5.f){
        pS2->setCooldown(pS2->getCooldown() + 0.03);
        return;
    }

    Entities::Character* pC1 =  static_cast<Entities::Character*>(pE1);
    pC1->setLife(pC1->getLife() - pE2->getDamage());

    pS2->setCooldown(0.f);
}