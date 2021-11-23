#include "Stages/ObstacleMaker.h"
using namespace Stages;


ObstacleMaker::ObstacleMaker(EntityList *pEL) {
    pEntityList = NULL;
    if (pEL)
        pEntityList = pEL;
}

ObstacleMaker::~ObstacleMaker() {
    pEntityList = NULL;
}

void ObstacleMaker::makeBarrel(Coordinates::Vector<float> pos) {
    Entities::Barrel* barrel = NULL;
    barrel = new Entities::Barrel(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(barrel));
    barrel = NULL;
}

void ObstacleMaker::makeOilTile(Coordinates::Vector<float> pos) {
    Entities::OilTile* oilTile = NULL;
    oilTile = new Entities::OilTile(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(oilTile));
    oilTile = NULL;
}

void ObstacleMaker::makeFire(Coordinates::Vector<float> pos) {
    Entities::Fire* fire = NULL;
    fire = new Entities::Fire(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(fire));
    fire = NULL;
}

void ObstacleMaker::makeSign(Coordinates::Vector<float> pos) {
    Entities::Sign* sign = NULL;
    sign = new Entities::Sign(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(sign));
    sign = NULL;
}

