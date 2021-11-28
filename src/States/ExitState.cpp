#include "States/GameStateMachine.h"
using namespace States;

ExitState::ExitState(GameStateMachine* pGM) {
    if (pGM)
        pGameStateMachine = pGM;
}

ExitState::~ExitState() {
}

void ExitState::update(float dt) {
    return ;
}

void ExitState::render() {
    return ;
}

void ExitState::reset() {
    exec() ;
}

void ExitState::exec() {
    if (pGameStateMachine)
        pGameStateMachine->endGame();
}