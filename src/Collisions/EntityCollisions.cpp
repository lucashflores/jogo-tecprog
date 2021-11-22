#include "Collisions/EntityCollisions.h"
using namespace Collisions;
#include <iostream>
#include <Entities/Smoke.h>

EntityCollisions::EntityCollisions() {}

EntityCollisions::~EntityCollisions() {}

void EntityCollisions::playerCollision(Entities::Entity *pE1, Entities::Entity *pE2, Coordinates::Vector<float> collision) {
    if (pE1->getPosition().getX() > pE2->getPosition().getX())
        pE1->setPosition(Coordinates::Vector<float>(pE1->getPosition().getX() + collision.getX(), pE1->getPosition().getY()));

    else
        pE1->setPosition(Coordinates::Vector<float>(pE1->getPosition().getX() - collision.getX(), pE1->getPosition().getY()));

    if (pE1->getId() == Id::projectile)
        pE1->eliminate();
}

void EntityCollisions::enemyCollision(Entities::Entity *pE1, Entities::Entity *pE2,
                                      Coordinates::Vector<float> collision) {
    if (pE1->getPosition().getX() > pE2->getPosition().getX())
        pE1->setPosition(Coordinates::Vector<float>(pE1->getPosition().getX() + collision.getX(), pE1->getPosition().getY()));

    else
        pE1->setPosition(Coordinates::Vector<float>(pE1->getPosition().getX() - collision.getX(), pE1->getPosition().getY()));

}

void EntityCollisions::projectileCollision(Entities::Entity *pE1, Entities::Entity *pE2,
                                           Coordinates::Vector<float> collision) {
    Entities::Character* pC1 =  static_cast<Entities::Character*>(pE1);
    pC1->setLife(pC1->getLife() - pE2->getDamage());
    std::cout << "Deu dano!" << std::endl << " Vida player: " << pC1->getLife() << std::endl;
}

void EntityCollisions::smokeCollision(Entities::Entity *pE1, Entities::Entity *pE2,
                                           Coordinates::Vector<float> collision) {
    Entities::Smoke* pS2 = static_cast < Entities::Smoke*>(pE2);
    if (pS2->getCooldown() < 5.f){
        pS2->setCooldown(pS2->getCooldown() + 0.02);
        return;
    }

    Entities::Character* pC1 =  static_cast<Entities::Character*>(pE1);
    pC1->setLife(pC1->getLife() - pE2->getDamage());
    std::cout << "Deu dano!" << std::endl << " Vida player: " << pC1->getLife() << std::endl;

    pS2->setCooldown(0.f);
}