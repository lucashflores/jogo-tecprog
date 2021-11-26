#pragma once
#include "State.h"

#include "Menus/Menu.h"

namespace States {

    class GameStateMachine;

    class MainMenuState: public State, public Menus::Menu {
    private:
        GameStateMachine* pGameStateMachine;
        Managers::InputManager* pInputManager;
    public:
        MainMenuState(GameStateMachine* pGM);
        ~MainMenuState();
        void createButtons();
        void update(float dt);
        void render();
        void reset();
        void exec();
        void select();
        void back();
    };
}