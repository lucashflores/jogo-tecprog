#include "States/GameStateMachine.h"
using namespace States;

CreatingStage1State::CreatingStage1State(GameStateMachine* pGM) {
    if (pGM)
        pGameStateMachine = pGM;
}

CreatingStage1State::~CreatingStage1State() {
    pGameStateMachine = NULL;
}

void CreatingStage1State::update(float dt) {
    exec();
}

void CreatingStage1State::render() {}

void CreatingStage1State::reset() {

}

void CreatingStage1State::exec() {
    Stages::Stage1Factory* stageFactory = new Stages::Stage1Factory();
    Stages::Stage* stage = NULL;
    if (pGameStateMachine->getTwoPlayers())
        stage = stageFactory->requestStage(pGameStateMachine->getPLayer1(), pGameStateMachine->getPLayer2());
    else
        stage = stageFactory->requestStage(pGameStateMachine->getPLayer1(), NULL);
    pGameStateMachine->setStage(stage);
    changeState("PlayingState");
}



