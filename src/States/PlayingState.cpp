#include "States/GameStateMachine.h"
using namespace States;

PlayingState::PlayingState(GameStateMachine* pGM) {
    if (pGM)
        pGameStateMachine = pGM;
}

PlayingState::~PlayingState() {
    pGameStateMachine = NULL;
}

void PlayingState::update(float dt) {
    (pGameStateMachine->getStage())->exec(dt);
}

void PlayingState::exec() {

}

void PlayingState::reset() {

}

void PlayingState::render() {

}
