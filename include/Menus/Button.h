#pragma once
#include <string>
#include "Ent.h"
#include "Text.h"
#include "Managers/GraphicManager.h"

#define BUTTON_PATH "../assets/button.png"


namespace Menus {

    class Button: public Ent {
    private:
        Managers::GraphicManager* pGraphicM;
        bool selected;
        Text* text;
    public:
        Button(Coordinates::Vector<float> pos, std::string t);
        ~Button();
        void initializeSprite();
        void setSelected(bool s);
        bool getSelected() const;
        void render();
        void update();
    };
}