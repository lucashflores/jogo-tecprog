#include "States/GameStateMachine.h"
using namespace States;

GameStateMachine::GameStateMachine() {
    pGraphicM = Managers::GraphicManager::getInstance();
    pEventM = Managers::EventManager::getInstance();
    pInputM = Managers::InputManager::getInstance();
    pStage = NULL;
    player1 = new Entities::Player(true);
    player2 = new Entities::Player(false);
    currentStage = 1;
    initializeStates();

}

GameStateMachine::~GameStateMachine() {
    pStage = NULL;
    delete player1;
    delete player2;
}

void GameStateMachine::initializeStates() {
    try {
        stateList["MainMenuState"] = new MainMenuState(this);
        stateList.at("MainMenuState")->setStateMachine(static_cast<StateMachine*>(this));
        stateList["ExitState"] = new ExitState(this);
        stateList.at("ExitState")->setStateMachine(static_cast<StateMachine*>(this));
        currentState = static_cast<State*>(stateList.at("MainMenuState"));
    }
    catch (...) {
        std::cout << "States not loaded!" << std::endl;
        exit(1);
    };
}

void GameStateMachine::exec() {
    float dt;
    sf::Clock clock;

    while (pGraphicM->isWindowOpen()) {
        sf::Event event;

        pEventM->pollEvents(event);

        dt = clock.restart().asSeconds();

        if (dt > 0.0167)
            dt = 0.0167;

        pGraphicM->clear();
        updateCurrentState(dt);
        pInputM->clearKeyPressedInFrame();
        pGraphicM->display();

    }
}

void GameStateMachine::save() {

}

void GameStateMachine::setCurrentStage(int num) {
    currentStage = num;
}

void GameStateMachine::setStage(Stages::Stage *pS) {
    if (pS)
        pStage = pS;
}

Stages::Stage *GameStateMachine::getStage() const {
    return pStage;
}

Entities::Player *GameStateMachine::getPLayer1() {
    return player1;
}

Entities::Player *GameStateMachine::getPLayer2() {
    return player2;
}

void GameStateMachine::loadGame() {
    Stages::StageLoader* stageLoader = new Stages::StageLoader();
    stageLoader->loadPlayer1(player1);
    stageLoader->loadPlayer2(player2);
    setStage(stageLoader->loadStage(player1, player2));
    currentStage = getStage()->getStageNumber();
}

void GameStateMachine::endGame() {
    if (pGraphicM)
        pGraphicM->closeWindow();
}

