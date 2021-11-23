#include "States/PlayingState.h"
using namespace States;

PlayingState::PlayingState(Stages::Stage* pS) {
    pStage = NULL;
    setStage(pS);
}

PlayingState::~PlayingState() {
    pStage = NULL;
}

void PlayingState::setStage(Stages::Stage *pS) {
    if (pS)
        pStage = NULL;
}

Stages::Stage *PlayingState::getStage() {
    return pStage;
}

void PlayingState::exec(float dt) {
    pStage->exec(dt);
}