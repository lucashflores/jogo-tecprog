#pragma once
#include "State.h"
#include "Menus/Menu.h"


namespace States {
    class GameStateMachine;

    class PlayingState: public State, public Menus::Menu {
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
        void createButtons();
        void select();
        void back();
    };
}