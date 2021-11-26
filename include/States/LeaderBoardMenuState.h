#pragma once
#include "State.h"
#include "Menus/Menu.h"

namespace States {

    class GameStateMachine;

    class LeaderBoardMenuState {
    private:
        GameStateMachine* pGameStateMachine;
        std::map<std::string, unsigned int> leaderboard;
    public:
        LeaderBoardMenuState(GameStateMachine* pGM);
        ~LeaderBoardMenuState();
        void createButtons();
        void update(float dt);
        void render();
        void reset();
        void exec();
        void select();
        void back();
    };
}
