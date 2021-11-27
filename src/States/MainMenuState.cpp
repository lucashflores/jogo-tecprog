#include "States/GameStateMachine.h"
using namespace States;

MainMenuState::MainMenuState(GameStateMachine* pGM) {
    pGameStateMachine = pGM;
    createButtons();
    buttons[buttonSelected]->setSelected(true);
}

MainMenuState::~MainMenuState() {
}

void MainMenuState::createButtons() {
    Menus::Button* b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 80.f), "New Game");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 230.f), "Stage2");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 380.f), "Load Game");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 530.f), "Leaderboard");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 680.f), "Exit");
    buttons.push_back(b);
    b = NULL;
}

void MainMenuState::exec() {
    if (buttonSelected == 0)
        changeState("NewGameMenuState");
    else if (buttonSelected == 1)
        changeState("NewStage2MenuState");
    else if (buttonSelected == 2)
        changeState("LoadGameState");
    else if (buttonSelected == 3)
        changeState("LeaderBoardMenuState");
    else if (buttonSelected == 4)
        changeState("ExitState");
    else
        return;
}

void MainMenuState::reset() {
    pGameStateMachine->clearKeyPressedInFrame();
    updateButtons();
    render();
}

void MainMenuState::render() {
    renderItems();
}

void MainMenuState::update(float dt) {
    updateButtons();
    render();
}


void MainMenuState::select() {
    exec();
}

void MainMenuState::back() {
    changeState("ExitState");
}