#include "States/GameStateMachine.h"
using namespace States;

CreatingStage2State::CreatingStage2State(GameStateMachine* pGM) {
    if (pGM)
        pGameStateMachine = pGM;
}

CreatingStage2State::~CreatingStage2State() {
    pGameStateMachine = NULL;
}

void CreatingStage2State::update(float dt) {
    exec();
}

void CreatingStage2State::render() {}

void CreatingStage2State::reset() {

}

void CreatingStage2State::exec() {
    Stages::Stage2Factory* stageFactory = new Stages::Stage2Factory();
    Stages::Stage* stage = NULL;
    if (pGameStateMachine->getTwoPlayers())
        stage = stageFactory->requestStage(pGameStateMachine->getPLayer1(), pGameStateMachine->getPLayer2());
    else
        stage = stageFactory->requestStage(pGameStateMachine->getPLayer1(), NULL);
    pGameStateMachine->setStage(stage);
    changeState("PlayingState");
}



