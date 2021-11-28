#include "Stages/ProjectileMaker.h"
using namespace Stages;

ProjectileMaker::ProjectileMaker() {}

ProjectileMaker::ProjectileMaker(EntityList* pEL) {
    if (pEL)
        entityList = pEL;
}

ProjectileMaker::~ProjectileMaker() {
    if (entityList)
        entityList = NULL;
}

void ProjectileMaker::makeProjectile(Coordinates::Vector<float> pos, bool isFacingLeft) {
    Entities::Projectile* projectile = NULL;
    projectile = new Entities::Projectile(pos, isFacingLeft);
    entityList->addEntity(static_cast<Entities::Entity*>(projectile));
    projectile = NULL;
}

void ProjectileMaker::makeSmoke(Coordinates::Vector<float> pos) {
    Entities::Smoke* smoke = NULL;
    smoke = new Entities::Smoke(pos);
    entityList->addEntity(static_cast<Entities::Entity*>(smoke));
    smoke = NULL;
}

Entities::Projectile* ProjectileMaker::loadProjectile(Coordinates::Vector<float> pos, bool isFacingLeft) {
    Entities::Projectile* projectile = NULL;
    projectile = new Entities::Projectile(pos, isFacingLeft);
    return projectile;
}

Entities::Smoke *ProjectileMaker::loadSmoke(Coordinates::Vector<float> pos) {
    Entities::Smoke* smoke = NULL;
    smoke = new Entities::Smoke(pos);
    return smoke;
}

