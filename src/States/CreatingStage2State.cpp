#include "States/GameStateMachine.h"
using namespace States;
#include "Concurrent/BossThread.h"

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
    pGameStateMachine->getPLayer1()->reset();
    if (pGameStateMachine->getTwoPlayers())
        pGameStateMachine->getPLayer2()->reset();
}

void CreatingStage2State::exec() {
    Stages::Stage2Factory* stageFactory = new Stages::Stage2Factory();
    Stages::Stage* stage = NULL;
    if (pGameStateMachine->getTwoPlayers())
        stage = stageFactory->requestStage(pGameStateMachine->getPLayer1(), pGameStateMachine->getPLayer2());
    else
        stage = stageFactory->requestStage(pGameStateMachine->getPLayer1(), NULL);
    pGameStateMachine->getPLayer1()->setPosition(Coordinates::Vector<float>(INITIALPOS_X, INITIALPOST_Y));
    if (pGameStateMachine->getTwoPlayers())
        pGameStateMachine->getPLayer2()->setPosition(Coordinates::Vector<float>(INITIALPOS_X, INITIALPOST_Y));
    pGameStateMachine->setStage(stage);
    Concurrent::BossThread::unlock();

    changeState("PlayingState");
}



