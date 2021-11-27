#pragma once

#pragma once

#include "Stage.h"
#define INITIALPOS_X 150.f
#define INITIALPOST_Y 950.f

namespace Stages {

    class Stage2: public Stage {
    public:
        Stage2(EntityList* pEL, Entities::Player* player1, Entities::Player* player2);
        ~Stage2();
    };
}
