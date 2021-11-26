#include "States/GameStateMachine.h"
using namespace States;

LeaderBoardMenuState::LeaderBoardMenuState(GameStateMachine *pGM) {
    if (pGM)
        pGameStateMachine = pGM;
}

LeaderBoardMenuState::~LeaderBoardMenuState() {
    for (auto it = leaderboard.begin(); it != leaderboard.end(); it++) {

    }
}

void LeaderBoardMenuState::createButtons() {

}