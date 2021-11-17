#pragma once

#include "EntityList.h"
#include "EnemySpawner.h"
#include "ObstacleBuilder.h"
#include "TileMaker.h"

namespace Stages {
    class StageBuilder {
    private:
        EntityList* pEntityList;
        int stage;
    public:
        StageBuilder(int stg, EntityList* pEL);
        ~StageBuilder();
        void buildStage(std::string stageInstructionsPath);
    };
}