#include "Menus/MenuControl.h"
#include "Menus/Menu.h"
using namespace Menus;


MenuControl::MenuControl(Menu* m): controls() {
    if (m)
        menu = m;
    pInputManager = Managers::InputManager::getInstance();
    initializeControls();
}

MenuControl::~MenuControl() {
    menu = NULL;
    pInputManager = NULL;
}

void MenuControl::initializeControls() {
    controls["moveUp"] = "Up";
    controls["moveDown"] = "Down";
    controls["select"] = "Enter";
}

void MenuControl::notify() {
    if (pInputManager->wasKeyPressed("moveUp"))
        menu->moveUp();
    else if (pInputManager->wasKeyPressed("moveDown"))
        menu->moveDown();
    else if (pInputManager->wasKeyPressed("select"))
        menu->select();
    else
        return ;
}