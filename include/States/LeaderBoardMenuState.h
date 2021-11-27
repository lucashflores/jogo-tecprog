#pragma once
#include "State.h"
#include "Menus/LeaderBoardMenu.h"
#include <fstream>


namespace States {

    class GameStateMachine;

    class LeaderBoardMenuState: public State, public Menus::LeaderBoardMenu {
    private:
        GameStateMachine* pGameStateMachine;

    public:
        LeaderBoardMenuState(GameStateMachine* pGM);
        ~LeaderBoardMenuState();
        std::vector<std::string> convertStringToVector(std::string s, std::vector<std::string> commands);
        void loadLeaderBoard();
        void update(float dt);
        void render();
        void reset();
        void exec();
        void select();
        void back();
    };
}
