#pragma once
#include "State.h"

#include "Menus/MainMenu.h"

namespace States {

    class GameStateMachine;

    class MainMenuState: public State, public Menus::MainMenu {
    private:
        GameStateMachine* pGameStateMachine;
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