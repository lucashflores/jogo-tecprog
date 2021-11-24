#pragma once

#pragma once

#include "Stage.h"

namespace Stages {

    class Stage2: public Stage {
    public:
        Stage2(EntityList* pEL, Entities::Player* player1, Entities::Player* player2);
        ~Stage2();
        //int getStageNumber();
    };
}
