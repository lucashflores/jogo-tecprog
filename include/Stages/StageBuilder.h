#pragma once

#include "EntityList.h"
#include "EnemySpawner.h"
#include "ObstacleBuilder.h"
#include "PlatformMaker.h"

namespace Stages {
    class StageBuilder {
    private:
        EntityList* pEntityList;
    public:
        StageBuilder(EntityList* pEL);
        ~StageBuilder();
        void buildStage(std::string stageInstructionsPath);
    };
}