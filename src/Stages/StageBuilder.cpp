#include "Stages/StageBuilder.h"
using namespace Stages;

StageBuilder::StageBuilder(int stg, EntityList *pEL) {
    pEntityList = NULL;
    if (pEL)
        pEntityList = pEL;
    stage = stg;
    if (stage != 1 && stage != 2)
        stage = 1;
}

StageBuilder::~StageBuilder() {
    pEntityList = NULL;
}

void StageBuilder::buildStage(std::string stageInstructionsPath) {

}