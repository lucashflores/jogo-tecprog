#include "States/NewGameState.h"
using namespace States;

NewGameState::NewGameState(GameStateMachine* gm) {
    if (gm)
        game = gm;
}

NewGameState::~NewGameState() {
    game = NULL;
}

void NewGameState::startNewStage(int stg, bool twoPlayers) {
    Stages::StageFactory* stageFactory = NULL;
    if (stg == 2)
        stageFactory = static_cast<Stages::StageFactory*>(new Stages::Stage2Factory());
    else
        stageFactory = static_cast<Stages::StageFactory*>(new Stages::Stage1Factory());

    Stages::Stage* stage = NULL;
    if (twoPlayers)
        stage = stageFactory->requestStage(game->getPLayer1(), game->getPLayer2());
    else
        stage = stageFactory->requestStage(game->getPLayer1(), NULL);
    game->setStage(stage);
    game->setCurrentStage(stg);
    //changeState()
}

void NewGameState::update(float dt) {
    return ;
}

void NewGameState::render() {
    return ;
}

void NewGameState::exec() {
    return ;
}