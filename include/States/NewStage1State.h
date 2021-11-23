#pragma once
#include "State.h"
#include "Stages/Stage1Factory.h"
#include "Entities/Player.h"

namespace States {
    class NewStage1State: public State {
    public:
        NewStage1State(Entities::Player* p1, Entities::Player* p2);
        ~NewStage1State();
        void exec(Entities::Player* p1, Entities::Player* p2);
    };
}