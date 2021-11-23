#include "Collisions/TileCollisionDealer.h"
using namespace Collisions;

TileCollisionDealer::TileCollisionDealer() {

}

TileCollisionDealer::~TileCollisionDealer() {}

void TileCollisionDealer::groundCollision(Entities::Entity *pE1, Entities::Entity *pE2, Coordinates::Vector<float> collision) {
    Entities::Character* pC1 =  static_cast<Entities::Character*>(pE1);
    pC1->setIsOnGround(true);
    pC1->setPosition(Coordinates::Vector<float>(pC1->getPosition().getX(), pC1->getPosition().getY() - collision.getY()));

}

void TileCollisionDealer::roofCollision(Entities::Entity *pE1, Entities::Entity *pE2, Coordinates::Vector<float> collision) {
    Entities::Character* pC1 =  static_cast<Entities::Character*>(pE1);
    pC1->setVelocity(Coordinates::Vector<float>(pC1->getVelocity().getX(), 0.f));
    pC1->setPosition(Coordinates::Vector<float>(pC1->getPosition().getX(), pC1->getPosition().getY() + collision.getY()));
}

void TileCollisionDealer::wallCollision(Entities::Entity *pE1, Entities::Entity *pE2, Coordinates::Vector<float> collision) {
    Entities::Character* pC1 =  static_cast<Entities::Character*>(pE1);
    if (pC1->getPosition().getX() < pE2->getPosition().getX()) {
        pC1->setPosition(Coordinates::Vector<float>(pC1->getPosition().getX() - collision.getX(), pC1->getPosition().getY()));
    }
    else
        pC1->setPosition(Coordinates::Vector<float>(pC1->getPosition().getX() + collision.getX(), pC1->getPosition().getY()));

    pC1->setVelocity(Coordinates::Vector<float>(0.f, pC1->getVelocity().getY()));
    if (pC1->getVelocity().getY() < 0) {
        pC1->setVelocity(Coordinates::Vector<float>(pC1->getVelocity().getX(), 0.f));
    }

}
