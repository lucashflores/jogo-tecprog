    #pragma once
#include "Managers/InputManager.h"
#include "TextInput.h"
#include <map>
#include <string>

namespace Menus {
    class TextInput;

    class TextControl {
    private:
        Managers::InputManager* pInputManager;
        TextInput* pTextInput;
        std::map<std::string, std::string> controls;
    public:
        TextControl(TextInput* pTI);
        ~TextControl();
        void initializeControls();
        std::string notify();
    };
}
