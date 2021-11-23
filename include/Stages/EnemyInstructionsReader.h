#pragma once
#include "EnemyMaker.h"
#include "InstructionsReader.h"

namespace Stages {

    class EnemyInstructionsReader: public InstructionsReader {
    private:
        EnemyMaker* pEnemyMaker;
    public:
        EnemyInstructionsReader(EntityList* pEL);
        ~EnemyInstructionsReader();
        void executeInstructions();
    };

}