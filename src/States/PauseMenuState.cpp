#include "States/GameStateMachine.h"
using namespace States;

PauseMenuState::PauseMenuState(GameStateMachine *pGM) {
    if (pGM)
        pGameStateMachine = pGM;
    pInputManager = Managers::InputManager::getInstance();
    buttonSelected = 0;
    createButtons();
    buttons[buttonSelected]->setSelected(true);
    menuTitle = NULL;
}

PauseMenuState::~PauseMenuState() {
    pGameStateMachine = NULL;
}

void PauseMenuState::createButtons() {
    Menus::Button* b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 150.f), "Resume");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 300.f), "Save Game");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 450.f), "Main Menu");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 600.f), "Exit");
    buttons.push_back(b);
    b = NULL;
}

void PauseMenuState::exec() {
    if (buttonSelected == 0)
        changeState("PlayingState");
    else if (buttonSelected == 1)
        changeState("SaveGameState");
    else if (buttonSelected == 2)
        changeState("MainMenuState");
    else if (buttonSelected == 3)
        changeState("ExitState");
    else
        return;
}

void PauseMenuState::render() {
    pGameStateMachine->setGameViewSize(Coordinates::Vector<float>(1280.f, 720.f));
    pGameStateMachine->centerGameView(Coordinates::Vector<float>(640.f ,360.f));
    renderItems();
}

void PauseMenuState::update(float dt) {
    updateButtons();
    render();
}

void PauseMenuState::reset() {
    pGameStateMachine->setGameViewSize(Coordinates::Vector<float>(1280.f, 720.f));
    pGameStateMachine->centerGameView(Coordinates::Vector<float>(640.f ,360.f));
    buttonSelected = 0;
    pInputManager->clearKeyPressedInFrame();
    updateButtons();
    render();
}

void PauseMenuState::select() {
    exec();
}

void PauseMenuState::back() {
    changeState("PlayingState");
}
