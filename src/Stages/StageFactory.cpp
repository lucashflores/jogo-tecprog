#include "Stages/StageFactory.h"
using namespace Stages;

StageFactory::StageFactory(int stg):stage(stg) {
    entityList = new EntityList();
}

StageFactory::~StageFactory() {

    entityList = NULL;
}
