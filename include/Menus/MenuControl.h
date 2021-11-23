#pragma once
#include "Managers/InputManager.h"

namespace Menus {
    class Menu;

    class MenuControl {
    private:
        std::map<std::string, std::string> controls;
        Menu* menu;
        Managers::InputManager *pInputManager;
    public:
        MenuControl(Menu* m);
        ~MenuControl();
        void initializeControls();
        void notify();
    };
}