#include "States/GameStateMachine.h"
using namespace States;

SavingLeaderBoardState::SavingLeaderBoardState(GameStateMachine *pGM) {
    if (pGM)
        pGameStateMachine = pGM;
}

SavingLeaderBoardState::~SavingLeaderBoardState() {
    pGameStateMachine = NULL;
}

void SavingLeaderBoardState::update(float dt) {
    exec();
}

void SavingLeaderBoardState::render() {
    return ;
}

void SavingLeaderBoardState::reset() {
    return ;
}

void SavingLeaderBoardState::exec() {
    saveLeaderBoard();
    changeState("LeaderBoardMenuState");
}

void SavingLeaderBoardState::saveLeaderBoard() {

    std::ofstream leaderBoardSave(LEADERBOARD_SAVE, std::ios::app);

    leaderBoardSave << pGameStateMachine->getScore() << " " << pGameStateMachine->getName() << "\n";

    leaderBoardSave.close();
}

