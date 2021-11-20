#pragma once

#include "ObstacleFactory.h"
#include "InstructionsReader.h"

namespace Stages {

    class ObstacleInstructionsReader: public InstructionsReader  {
    private:
        ObstacleFactory* pObstacleFactory;
    public:
        ObstacleInstructionsReader(ObstacleFactory* pOF);
        ~ObstacleInstructionsReader();
        void executeInstructions();
    };

}