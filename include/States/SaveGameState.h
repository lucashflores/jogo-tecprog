#pragma once
#include "State.h"

namespace States {

    class GameStateMachine;

    class SaveGameState: public State {
    private:
        GameStateMachine* pGameStateMachine;
    public:
        SaveGameState(GameStateMachine* pGM);
        ~SaveGameState();
        void update(float dt);
        void render();
        void reset();
        void exec();
    };
}