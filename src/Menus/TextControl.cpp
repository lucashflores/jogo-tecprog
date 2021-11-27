#include "Menus/TextInput.h"
using namespace Menus;

TextControl::TextControl(TextInput *pTI) {
    if (pTI)
        pTextInput = pTI;
    pInputManager = Managers::InputManager::getInstance();
    initializeControls();
}

TextControl::~TextControl() {
    pInputManager = NULL;
}

void TextControl::initializeControls() {
    controls["Erase"] = "BackSpace";
    controls["A"] = "A";
    controls["B"] = "B";
    controls["C"] = "C";
    controls["D"] = "D";
    controls["E"] = "E";
    controls["F"] = "F";
    controls["G"] = "G";
    controls["H"] = "H";
    controls["I"] = "I";
    controls["J"] = "J";
    controls["K"] = "K";
    controls["L"] = "L";
    controls["M"] = "M";
    controls["N"] = "N";
    controls["O"] = "O";
    controls["P"] = "P";
    controls["Q"] = "Q";
    controls["R"] = "R";
    controls["S"] = "S";
    controls["T"] = "T";
    controls["U"] = "U";
    controls["V"] = "V";
    controls["W"] = "W";
    controls["X"] = "X";
    controls["Y"] = "Y";
    controls["Z"] = "Z";
    controls["1"] = "1";
    controls["2"] = "2";
    controls["3"] = "3";
    controls["4"] = "4";
    controls["5"] = "5";
    controls["6"] = "6";
    controls["7"] = "7";
    controls["8"] = "8";
    controls["9"] = "9";
    controls["0"] = "0";

}

std::string TextControl::notify() {
    if (pInputManager->wasKeyPressedInFrame(controls.at("Erase")))
        pTextInput->erase();
    else {
        for (auto it = controls.begin(); it != controls.end(); it++) {
            if (it->first != "Erase") {
                if (pInputManager->wasKeyPressedInFrame(it->first))
                    return it->second;
            }
        }
    }
    return "";
}