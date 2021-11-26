#include "States/GameStateMachine.h"
using namespace States;

GameStateMachine::GameStateMachine() {
    pGraphicM = Managers::GraphicManager::getInstance();
    pEventM = Managers::EventManager::getInstance();
    pInputM = Managers::InputManager::getInstance();
    pStage = NULL;
    twoPlayers = false;
    score = 0;
    player1 = new Entities::Player(true);
    player2 = new Entities::Player(false);
    currentStage = 1;
    initializeStates();

}

GameStateMachine::~GameStateMachine() {
    pStage = NULL;
    if (pStage)
        delete pStage;
    delete player1;
    delete player2;
}

void GameStateMachine::initializeStates() {
    try {
        stateList["MainMenuState"] = new MainMenuState(this);
        stateList.at("MainMenuState")->setStateMachine(static_cast<StateMachine*>(this));

        stateList["ExitState"] = new ExitState(this);
        stateList.at("ExitState")->setStateMachine(static_cast<StateMachine*>(this));

        stateList["NewGameMenuState"] = new NewGameMenuState(this);
        stateList.at("NewGameMenuState")->setStateMachine(static_cast<StateMachine*>(this));

        stateList["CreatingStage1State"] = new CreatingStage1State(this);
        stateList.at("CreatingStage1State")->setStateMachine(static_cast<StateMachine*>(this));

        stateList["PlayingState"] = new PlayingState(this);
        stateList.at("PlayingState")->setStateMachine(static_cast<StateMachine*>(this));

        stateList["NewStage2MenuState"] = new NewStage2MenuState(this);
        stateList.at("NewStage2MenuState")->setStateMachine(static_cast<StateMachine*>(this));

        stateList["CreatingStage2State"] = new CreatingStage2State(this);
        stateList.at("CreatingStage2State")->setStateMachine(static_cast<StateMachine*>(this));

        stateList["PauseMenuState"] = new PauseMenuState(this);
        stateList.at("PauseMenuState")->setStateMachine(static_cast<StateMachine*>(this));

        stateList["LoadGameState"] = new LoadGameState(this);
        stateList.at("LoadGameState")->setStateMachine(static_cast<StateMachine*>(this));

        stateList["SaveGameState"] = new SaveGameState(this);
        stateList.at("SaveGameState")->setStateMachine(static_cast<StateMachine*>(this));

        stateList["EndGameMenuState"] = new EndGameMenuState(this);
        stateList.at("EndGameMenuState")->setStateMachine(static_cast<StateMachine*>(this));

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




void GameStateMachine::setCurrentStage(int num) {
    currentStage = num;
}

int GameStateMachine::getCurrentStage() const {
    return currentStage;
}


void GameStateMachine::setStage(Stages::Stage *pS) {
    if (pS)
        pStage = pS;
    setCurrentStage(pStage->getStageNumber());
}

Stages::Stage *GameStateMachine::getStage() const {
    return pStage;
}


void GameStateMachine::setName(std::string n) {
    name = n;
}

std::string GameStateMachine::getName() {
    return name;
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


void GameStateMachine::setTwoPlayers(bool tp) {
    twoPlayers = tp;
}

bool GameStateMachine::getTwoPlayers() const {
    return twoPlayers;
}


void GameStateMachine::setGameViewSize(Coordinates::Vector<float> size) {
    pGraphicM->setViewSize(size);
}

void GameStateMachine::centerGameView(Coordinates::Vector<float> pos) {
    pGraphicM->centerView(pos);
}


void GameStateMachine::setScore(unsigned int scr) {
    score = scr;
}

unsigned int GameStateMachine::getScore() {
    return score;
}

