#pragma once
#include "State.h"
#include "Menus/Text.h"

namespace States {
    class GameStateMachine;

    class PlayingState: public State {
    private:
        GameStateMachine* pGameStateMachine;
        Managers::InputManager* pInputManager;

    public:
        PlayingState(GameStateMachine* pGM);
        ~PlayingState();
        void update(float dt);
        void render();
        void reset();
        void exec();
        void back();
    };
}