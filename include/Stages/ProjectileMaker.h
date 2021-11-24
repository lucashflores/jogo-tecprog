#pragma once

#include "Entities/Smoke.h"
#include "Entities/Projectile.h"

namespace Stages {
    class ProjectileMaker {
    public:
        ProjectileMaker();
        ~ProjectileMaker();
        Entities::Projectile* makeProjectile(Coordinates::Vector<float> pos, bool isFacingLeft);
        Entities::Smoke* makeSmoke(Coordinates::Vector<float> pos);
    };
}