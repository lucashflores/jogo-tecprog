#pragma once
#include "EnemyMaker.h"
#include "InstructionsReader.h"

namespace Stages {

    class EnemyInstructionsReader: public InstructionsReader {
    private:
        EntityList* entityList;
        EnemyMaker* pEnemyMaker;
        Entities::Player* player1;
        Entities::Player* player2;
    public:
        EnemyInstructionsReader(EntityList *pEL, Entities::Player* player1, Entities::Player* player2);
        ~EnemyInstructionsReader();
        void executeInstructions();
    };

}