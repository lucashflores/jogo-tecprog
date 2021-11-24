#pragma once
#include "Button.h"
#include "Background.h"
#include "MenuControl.h"
#include <vector>

#define MENU_BACKGROUND "../assets/background.png"

namespace Menus {

    class Menu {
    protected:
        std::vector<Button*> buttons;
        Background* background;
        int buttonSelected;
        MenuControl* control;
    public:
        Menu();
        virtual ~Menu();
        virtual void createButtons() = 0;
        void createBackground();
        void renderItems();
        void updateButtons();
        void moveUp();
        void moveDown();
        virtual void select() = 0;
    };

}