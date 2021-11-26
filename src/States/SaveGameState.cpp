#include "States/GameStateMachine.h"
using namespace States;

SaveGameState::SaveGameState(GameStateMachine *pGM) {
    if (pGM)
        pGameStateMachine = pGM;
}

SaveGameState::~SaveGameState(){
    pGameStateMachine = NULL;
}

void SaveGameState::render() {
    return ;
}

void SaveGameState::reset() {
    return ;
}


void SaveGameState::update(float dt) {
    exec();
}

void SaveGameState::exec() {
    if (pGameStateMachine->getStage()) {
        pGameStateMachine->getStage()->save();
    }
    changeState("PlayingState");
}