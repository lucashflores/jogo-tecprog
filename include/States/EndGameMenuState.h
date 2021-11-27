#pragma once
#include "State.h"
#include "Menus/Menu.h"
#include "Menus/TextInput.h"

namespace States {

    class GameStateMachine;

    class EndGameMenuState: public State, public Menus::Menu {
    private:
        GameStateMachine* pGameStateMachine;
        Menus::TextInput* textInput;
        Menus::Text* menuTitle;
    public:
        EndGameMenuState(GameStateMachine* pGM);
        ~EndGameMenuState();
        void createButtons();
        void update(float dt);
        void render();
        void reset();
        void exec();
        void select();
        void back();
    };
}