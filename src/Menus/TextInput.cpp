#include "Menus/TextInput.h"
using namespace Menus;

TextInput::TextInput(Coordinates::Vector<float> pos, std::string labelText): Ent(Id::textBox), origin(pos) {
    textControl = new TextControl(this);

    initializeSprite();
    sprite->changePosition(pos);

    text = NULL;
    text = new Text(Coordinates::Vector<float>(pos.getX(), pos.getY() + 100.f), currentText);

    label = NULL;
    label = new Text(Coordinates::Vector<float>(pos.getX() - 110.f, pos.getY() - 20.f), labelText);
}

TextInput::~TextInput() {
    if (text)
        delete text;
    if (label)
        delete label;
    if (textControl)
        delete textControl;
}

std::string TextInput::getCurrentText() const {
    return currentText;
}

void TextInput::initializeSprite() {
    Coordinates::Vector<float> size = Coordinates::Vector<float>(500.f ,80.f);
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(1, 1);
    sprite = new Animation(BUTTON_PATH, size, imageCnt, 1.f);
}

void TextInput::render() {
    sprite->render();
    text->render();
    label->render();
}

void TextInput::update() {
    std::string character = textControl->notify();
    std::string ct = currentText;
    currentText = ct + character;
    if (character != "" && character != " ")
        text->setPosition(Coordinates::Vector<float>(text->getPosition().getX() - 6.48f, text->getPosition().getY()));
    text->setText(currentText);
    render();
}

void TextInput::erase() {
    if (currentText.size() > 0) {
        currentText.pop_back();
        text->setPosition(Coordinates::Vector<float>(text->getPosition().getX() + 6.48f, text->getPosition().getY()));
    }

}

void TextInput::reset() {
    currentText = "";
    text->setText(currentText);
    text->setPosition(origin);
}

//Nested Class definitions
TextInput::TextControl::TextControl(TextInput* pTI) {
    if (pTI)
        pTextInput = pTI;
    pInputManager = Managers::InputManager::getInstance();
    initializeControls();
}

TextInput::TextControl::~TextControl() {
    pInputManager = NULL;
}

void TextInput::TextControl::initializeControls() {
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

std::string TextInput::TextControl::notify() {
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
