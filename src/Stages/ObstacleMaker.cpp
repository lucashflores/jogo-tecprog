#include "Stages/ObstacleMaker.h"
using namespace Stages;


ObstacleMaker::ObstacleMaker() {
}

ObstacleMaker::~ObstacleMaker() {
}

Entities::Barrel* ObstacleMaker::makeBarrel(Coordinates::Vector<float> pos) {
    Entities::Barrel* barrel = NULL;
    barrel = new Entities::Barrel(pos);
    return barrel;
}

Entities::OilTile* ObstacleMaker::makeOilTile(Coordinates::Vector<float> pos) {
    Entities::OilTile* oilTile = NULL;
    oilTile = new Entities::OilTile(pos);
    return oilTile;
}

Entities::Fire* ObstacleMaker::makeFire(Coordinates::Vector<float> pos) {
    Entities::Fire* fire = NULL;
    fire = new Entities::Fire(pos);
    return fire;
}

Entities::Sign* ObstacleMaker::makeSign(Coordinates::Vector<float> pos) {
    Entities::Sign* sign = NULL;
    sign = new Entities::Sign(pos);
    return sign;
}

