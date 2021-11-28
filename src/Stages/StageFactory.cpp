#include "Stages/StageFactory.h"
using namespace Stages;

StageFactory::StageFactory(int stg):stage(stg) {
    entityList = new EntityList();
    projectileMaker = new ProjectileMaker(entityList);
}

StageFactory::~StageFactory() {
    entityList = NULL;
}
