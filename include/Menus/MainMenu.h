#pragma once

#include "Menus/Menu.h"

namespace Menus {
    class MainMenu: public Menu {
    public:
        Animation* bossSprite;
    public:
        MainMenu();
        ~MainMenu();
        virtual void select() = 0;
        virtual void back() = 0;
        virtual void createButtons() = 0;
    };
}