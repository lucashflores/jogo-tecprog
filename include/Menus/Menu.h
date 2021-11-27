#pragma once
#include "Button.h"
#include "Background.h"
#include "MenuControl.h"
#include "Text.h"

#include <vector>

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
        virtual void back() = 0;
    };

}