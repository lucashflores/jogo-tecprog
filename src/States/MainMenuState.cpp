#include "States/MainMenuState.h"
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
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 50.f), "New Game");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 200.f), "Stage1");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 350.f), "Stage2");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 500.f), "Load Game");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 650.f), "Exit");
    buttons.push_back(b);
    b = NULL;
}

void MainMenuState::exec() {
    if (buttonSelected == 0)
        changeState("NewGameState");
    else if (buttonSelected == 1)
        changeState("NewStage1State");
    else if (buttonSelected == 2)
        changeState("NewStage2State");
    else if (buttonSelected == 3)
        changeState("LoadGameState");
    else if (buttonSelected == 4)
        changeState("ExitState");
    else
        return;
}

void MainMenuState::reset() {
    buttonSelected = 0;
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