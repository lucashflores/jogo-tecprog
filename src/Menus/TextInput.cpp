#include "Menus/TextInput.h"
using namespace Menus;

TextInput::TextInput(Coordinates::Vector<float> pos, std::string labelText): Ent(Id::textBox), origin(pos) {
    textControl = new TextControl(this);

    initializeSprite();
    sprite->changePosition(pos);

    text = NULL;
    text = new Text(pos, currentText);

    label = NULL;
    label = new Text(Coordinates::Vector<float>(pos.getX() , pos.getY() - 17.f), labelText);
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