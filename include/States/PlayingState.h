#pragma once
#include "State.h"


namespace States {
    class GameStateMachine;

    class PlayingState: public State {
    private:
        GameStateMachine* pGameStateMachine;
    public:
        PlayingState(GameStateMachine* pGM);
        ~PlayingState();
        void update(float dt);
        void render();
        void reset();
        void exec();
    };
}