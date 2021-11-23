#pragma once
#include "Button.h"
#include "Background.h"
#include "MenuControl.h"
#include <vector>

#define FONT_PATH "../assets/font.ttf"
#define MENU_BACKGROUND "../assets/background.png"

namespace Menus {

    class Menu {
    private:
        std::vector<Button*> buttons;
        Background* background;
        int buttonSelected;
        MenuControl* control;
    public:
        Menu();
        ~Menu();
        virtual void createButtons() = 0;
        void createBackground();
        void renderItems();
        void update();
        void moveUp();
        void moveDown();
        int select();
    };

}