#pragma once

#include "State.h"
#include "Stages/Stage1Factory.h"
#include "Stages/Stage.h"

namespace States {

    class GameStateMachine;

    class CreatingStage1State: public State {
    private:
        GameStateMachine* pGameStateMachine;
    public:
        CreatingStage1State(GameStateMachine* pGM);
        ~CreatingStage1State();
        void update(float dt);
        void render();
        void reset();
        void exec();
    };
}