#pragma once
#include "EnemyMaker.h"
#include "InstructionsReader.h"

namespace Stages {

    class EnemyInstructionsReader: public InstructionsReader {
    private:
        EntityList* entityList;
        EnemyMaker* pEnemyMaker;
        ProjectileMaker* projectileMaker;
        Entities::Player* player1;
        Entities::Player* player2;
    public:
        EnemyInstructionsReader(EntityList *pEL, Entities::Player* p1, Entities::Player* p2, ProjectileMaker* pPM);
        ~EnemyInstructionsReader();
        void executeInstructions();
    };

}