#include "Stages/ProjectileMaker.h"
using namespace Stages;

ProjectileMaker::ProjectileMaker() {

}

ProjectileMaker::~ProjectileMaker() {

}

Entities::Projectile* ProjectileMaker::makeProjectile(Coordinates::Vector<float> pos, bool isFacingLeft) {
    Entities::Projectile* projectile = NULL;
    projectile = new Entities::Projectile(pos, isFacingLeft);
    return projectile;
}

Entities::Smoke *ProjectileMaker::makeSmoke(Coordinates::Vector<float> pos) {
    Entities::Smoke* smoke = NULL;
    smoke = new Entities::Smoke(pos);
    return smoke;
}

