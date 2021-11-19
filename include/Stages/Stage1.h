#pragma once

#include "Stage.h"

namespace Stages {

    class Stage1: public Stage {
    public:
        Stage1(EntityList* pEL, Entities::Player* player1, Entities::Player* player2);
        ~Stage1();
    };
}
