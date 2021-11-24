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
    if (pInputManager->wasKeyPressedInFrame(controls.at("moveUp")))
        menu->moveUp();
    else if (pInputManager->wasKeyPressedInFrame(controls.at("moveDown")))
        menu->moveDown();
    else if (pInputManager->wasKeyPressedInFrame(controls.at("select")))
        menu->select();
    else
        return ;

}