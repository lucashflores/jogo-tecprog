#include "Stages/ObstacleFactory.h"
#include "Stages/ObstacleInstructionsReader.h"
using namespace Stages;


ObstacleFactory::ObstacleFactory(EntityList *pEL) {
    pEntityList = NULL;
    if (pEL)
        pEntityList = pEL;
}

ObstacleFactory::~ObstacleFactory() {
    pEntityList = NULL;
}

void ObstacleFactory::readAndExecuteInstructions(std::string instructionsPath) {
    ObstacleInstructionsReader* instructionsReader = new ObstacleInstructionsReader(this);
    instructionsReader->readInstructions(instructionsPath);
    if (instructionsReader)
        delete instructionsReader;
}


void ObstacleFactory::makeBarrel(Coordinates::Vector<float> pos) {
    Entities::Barrel* barrel = NULL;
    barrel = new Entities::Barrel(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(barrel));
    barrel = NULL;
}

void ObstacleFactory::makeOilTile(Coordinates::Vector<float> pos) {
    Entities::OilTile* oilTile = NULL;
    oilTile = new Entities::OilTile(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(oilTile));
    oilTile = NULL;
}

void ObstacleFactory::makeFire(Coordinates::Vector<float> pos) {
    Entities::Fire* fire = NULL;
    fire = new Entities::Fire(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(fire));
    fire = NULL;
}

void ObstacleFactory::makeSign(Coordinates::Vector<float> pos) {
    Entities::Sign* sign = NULL;
    sign = new Entities::Sign(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(sign));
    sign = NULL;
}

