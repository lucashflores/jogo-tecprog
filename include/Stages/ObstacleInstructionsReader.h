#pragma once

#include "ObstacleMaker.h"
#include "InstructionsReader.h"

namespace Stages {

    class ObstacleInstructionsReader: public InstructionsReader  {
    private:
        EntityList* entityList;
        ObstacleMaker* pObstacleMaker;
    public:
        ObstacleInstructionsReader(EntityList* pEL);
        ~ObstacleInstructionsReader();
        void executeInstructions();
    };

}