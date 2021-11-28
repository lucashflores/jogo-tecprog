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
    b = new Menus::Button(Coordinates::Vector<float>(200.f, 120.f), "New Game");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(200.f, 250.f), "Stage2");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(200.f, 370.f), "Load Game");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(200.f, 490.f), "Leaderboard");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(200.f, 610.f), "Exit");
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
    bossSprite->render();
    menuTitle->render();
}

void MainMenuState::update(float dt) {
    updateButtons();
    bossSprite->animationUpdate(0, false, dt);
    render();
}


void MainMenuState::select() {
    exec();
}

void MainMenuState::back() {
    changeState("ExitState");
}