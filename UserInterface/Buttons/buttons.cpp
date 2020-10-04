//
// Created by boris on 14.09.2020.
//

#include "buttons.h"
#include "../../consts.h"

void Button::setColor(const sf::Color &color) {
    button.setFillColor(color);
}

void Button::setSize(const float rectWidth, const float rectHeight) {
    button.setSize(sf::Vector2f(rectWidth, rectHeight));
}

void Button::setPosition(const float x, const float y) {
    button.setPosition(x, y);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(button);
    target.draw(text);
}

void Button::setFont(const char *fontFile) {
    if (!font.loadFromFile(fontFile)) {
        throw FontLoadFromFileError();
    }
}

void Button::setText(const char *str, const char *fontFile, const sf::Color &color) {
    try {
        setFont(fontFile);
    } catch (FontLoadFromFileError& error) {
        printf("%s\n", error.what());
    }

    text.setString(str);
    text.setFont(font);
    text.setFillColor(color);

    text.setPosition(button.getPosition());
    float xOffset = (button.getSize().x - (text.findCharacterPos(MaxValues::maxCharactersInButtonText).x
            - text.findCharacterPos(0).x)) / 2;
    float yOffset = (button.getSize().y - text.getCharacterSize()) / 2;
    text.move(xOffset, yOffset);
}

void Button::setName(const char *fontFile, const sf::Color &color) {
    setText(name, fontFile, color);
}

bool Button::containMouse(const sf::Window& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (mousePosition.x >= button.getPosition().x &&
        mousePosition.y >= button.getPosition().y &&
        mousePosition.x <= button.getPosition().x + button.getSize().x &&
        mousePosition.y <= button.getPosition().y + button.getSize().y)
        return true;

    return false;
}

Button::Button(const char *name): name(name) {}

BubbleSortButton::BubbleSortButton(const char *name): Button(name) {}
MergeSortButton:: MergeSortButton(const char *name):  Button(name) {}
QuickSortButton:: QuickSortButton(const char *name):  Button(name) {}

void BubbleSortButton::onClick() {
    printf("Bubble sort!!!\n");
}

void MergeSortButton::onClick() {
    printf("Merge Sort!!!\n");
}

void QuickSortButton::onClick() {
    printf("Quick Sort!!!\n");
}
