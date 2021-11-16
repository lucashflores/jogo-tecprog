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

void ObstacleBuilder::buildBox(Coordinates::Vector<float> pos) {
    Entities::Box box = NULL;
    box = new Entities::Box(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(box));
    box = NULL;
}

void ObstacleBuilder::buildOilTile(Coordinates::Vector<float> pos) {
    Entities::OilTile oilTile = NULL;
    oilTile = new Entities::OilTile(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(oilTile));
    oilTile = NULL;
}

void ObstacleBuilder::buildFire(Coordinates::Vector<float> pos) {
    Entities::Fire fire = NULL;
    fire = new Entities::Fire(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(fire));
    fire = NULL;
}