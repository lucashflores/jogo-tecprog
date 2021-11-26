#include "Menus/TextInput.h"
using namespace Menus;

TextInput::TextInput(Coordinates::Vector<float> pos, std::string labelText): Ent(Id::textBox) {
    pGraphicM = Managers::GraphicManager::getInstance();
    textControl = new TextControl(this);

    initializeSprite();
    sprite->changePosition(pos);

    font = NULL;
    font = pGraphicM->loadFont(FONT_PATH);

    text = NULL;
    text = new sf::Text();
    text->setString(currentText);
    text->setFont(*font);
    text->setPosition(pos.getX(), pos.getY());
    text->setFillColor(sf::Color::White);

    label = NULL;
    label = new sf::Text();
    label->setString(labelText);
    label->setFont(*font);
    label->setPosition(pos.getX() - 120.f, pos.getY() - 45.f);
    label->setFillColor(sf::Color::White);
}

TextInput::~TextInput() {
    pGraphicM = NULL;
    if (text)
        delete text;
    if (label)
        delete label;
    font = NULL;
    textControl = NULL;
}

std::string TextInput::getCurrentText() const {
    return currentText;
}

void TextInput::initializeSprite() {
    Coordinates::Vector<float> size = Coordinates::Vector<float>(500.f ,100.f);
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(1, 1);
    sprite = new Animation(BUTTON_PATH, size, imageCnt, 1.f);
}

void TextInput::render() {
    sprite->render();
    pGraphicM->render(text);
    pGraphicM->render(label);
}

void TextInput::update() {
    std::string character = textControl->notify();
    std::string ct = currentText;
    currentText = ct + character;
    if (character != "" && character != " ")
        text->setPosition(text->getPosition().x - 6.48f, text->getPosition().y);
    text->setString(currentText);
    render();
}

void TextInput::erase() {
    if (currentText.size() > 0) {
        currentText.pop_back();
        text->setPosition(text->getPosition().x + 6.48f, text->getPosition().y);
    }

}