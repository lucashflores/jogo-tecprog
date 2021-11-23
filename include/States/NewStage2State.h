#pragma once
#include "State.h"
#include "Stages/Stage2Factory.h"
#include "Entities/Player.h"

namespace States {
    class NewStage2State: public State {
    public:
        NewStage2State(Entities::Player* p1, Entities::Player* p2);
        ~NewStage2State();
        void exec(Entities::Player* p1, Entities::Player* p2);
    };
}