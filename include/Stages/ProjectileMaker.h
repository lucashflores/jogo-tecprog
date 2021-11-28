#pragma once

#include "Entities/Smoke.h"
#include "Entities/Projectile.h"
#include "EntityList.h"

namespace Stages {
    class ProjectileMaker {
    private:
        EntityList* entityList;
    public:
        ProjectileMaker(EntityList* pEL);
        ProjectileMaker();
        ~ProjectileMaker();
        void makeProjectile(Coordinates::Vector<float> pos, bool isFacingLeft);
        void makeSmoke(Coordinates::Vector<float> pos);
        Entities::Projectile* loadProjectile(Coordinates::Vector<float> pos, bool isFacingLeft);
        Entities::Smoke* loadSmoke(Coordinates::Vector<float> pos);
    };
}