#pragma once

#include "State.h"
#include <ostream>

#define LEADERBOARD_SAVE "../saves/leaderBoardSave.txt"

namespace States {

    class GameStateMachine;

    class SavingLeaderBoardState: public State {
    private:
        GameStateMachine* pGameStateMachine;
    public:
        SavingLeaderBoardState(GameStateMachine* pGM);
        ~SavingLeaderBoardState();
        void update(float dt);
        void render();
        void reset();
        void exec();
        void saveLeaderBoard();
    };
}
