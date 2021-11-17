#include "Stages/ObstacleBuilder.h"
using namespace Stages;


ObstacleBuilder::ObstacleBuilder(EntityList *pEL) {
    pEntityList = NULL;
    if (pEL)
        pEntityList = pEL;
}

ObstacleBuilder::~ObstacleBuilder() {
    pEntityList = NULL;
}

void ObstacleBuilder::buildBarrel(Coordinates::Vector<float> pos) {
    Entities::Barrel* barrel = NULL;
    barrel = new Entities::Barrel(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(barrel));
    barrel = NULL;
}

void ObstacleBuilder::buildOilTile(Coordinates::Vector<float> pos) {
    Entities::OilTile* oilTile = NULL;
    oilTile = new Entities::OilTile(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(oilTile));
    oilTile = NULL;
}

void ObstacleBuilder::buildFire(Coordinates::Vector<float> pos) {
    Entities::Fire* fire = NULL;
    fire = new Entities::Fire(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(fire));
    fire = NULL;
}

void ObstacleBuilder::buildSign(Coordinates::Vector<float> pos) {
    Entities::Sign* sign = NULL;
    sign = new Entities::Sign(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(sign));
    sign = NULL;
}

