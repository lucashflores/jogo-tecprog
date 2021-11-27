#pragma once
#include "Text.h"
#include "TextControl.h"
#include "Ent.h"

#define BUTTON_PATH "../assets/button.png"
#define FONT_PATH "../assets/font.ttf"

namespace Menus {
    class TextInput: public Ent {
    private:
        std::string currentText;
        Text* text;
        Text* label;
        TextControl* textControl;
        Coordinates::Vector<float> origin;
    public:
        TextInput(Coordinates::Vector<float> pos, std::string labelText);
        ~TextInput();
        std::string getCurrentText() const;
        void initializeSprite();
        void render();
        void update();
        void erase();
        void reset();
    };
}