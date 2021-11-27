#pragma once
#include "State.h"

namespace States {
    class GameStateMachine;

    class LoadGameState: public State {
    private:
        GameStateMachine* pGameStateMachine;
    public:
        LoadGameState(GameStateMachine* pGM);
        ~LoadGameState();
        void update(float dt);
        void render();
        void reset();
        void exec();
    };
}