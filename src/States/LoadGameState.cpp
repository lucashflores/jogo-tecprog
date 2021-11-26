#include "States/GameStateMachine.h"
using namespace States;

LoadGameState::LoadGameState(GameStateMachine *pGM) {
    if (pGM)
        pGameStateMachine = pGM;
}

LoadGameState::~LoadGameState() noexcept {
    pGameStateMachine = NULL;
}

void LoadGameState::render() {
    return ;
}

void LoadGameState::reset() {
    return ;
}

void LoadGameState::update(float dt) {
    exec();
}

void LoadGameState::exec() {
    Stages::StageLoader* stageLoader = new Stages::StageLoader();
    stageLoader->loadPlayer1(pGameStateMachine->getPLayer1());
    stageLoader->loadPlayer2(pGameStateMachine->getPLayer2());
    pGameStateMachine->setStage(stageLoader->loadStage(pGameStateMachine->getPLayer1(), pGameStateMachine->getPLayer2()));
    changeState("PlayingState");
}

