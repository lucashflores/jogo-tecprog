#pragma once
#include "EnemyFactory.h"
#include "InstructionsReader.h"

namespace Stages {

    class EnemyInstructionsReader: public InstructionsReader {
    private:
        EnemyFactory* pEnemyFactory;
    public:
        EnemyInstructionsReader(EnemyFactory* pEF);
        ~EnemyInstructionsReader();
        void executeInstructions();
    };

}