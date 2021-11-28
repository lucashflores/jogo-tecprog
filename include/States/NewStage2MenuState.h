#pragma once
#include "State.h"
#include "Menus/Menu.h"
#include "Entities/Player.h"

namespace States {

    class GameStateMachine;

    class NewStage2MenuState: public State, public Menus::NewStageMenu {
    private:
        GameStateMachine* pGameStateMachine;
        Managers::InputManager* pInputManager;
    public:
        NewStage2MenuState(GameStateMachine* pGM);

        ~NewStage2MenuState();

        void createButtons();
        void update(float dt);
        void render();
        void reset();
        void exec();
        void select();
        void back();
    };
}