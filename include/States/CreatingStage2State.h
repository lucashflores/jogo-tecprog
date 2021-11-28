#pragma once

#include "State.h"
#include "Stages/Stage2Factory.h"
#include "Stages/Stage.h"

namespace States {

    class GameStateMachine;

    class CreatingStage2State: public State {
    private:
        GameStateMachine* pGameStateMachine;
    public:
        CreatingStage2State(GameStateMachine* pGM);
        ~CreatingStage2State();
        void update(float dt);
        void render();
        void reset();
        void exec();
    };
}