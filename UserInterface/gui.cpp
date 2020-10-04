#include "gui.h"
#include "../consts.h"

UserInterface::UserInterface():
    window(sf::RenderWindow(sf::VideoMode(uiWidth, uiHeight), "Sort Analyser")) {

    makeButtons();
}

UserInterface::~UserInterface() {
    for (size_t i = 0; i < buttonsCount; ++i) {
        delete buttons[i];
    }
    delete[] buttons;
}

UserInterface::UserInterface(size_t uiWidth, size_t uiHeight):
    uiWidth(uiWidth),
    uiHeight(uiHeight),
    window(sf::RenderWindow(sf::VideoMode(uiWidth, uiHeight), "Sort Analyser", sf::Style::Close)) {
}

void UserInterface::makeButtons() {
    buttons = new Button*[buttonsCount];

    buttons[0] = new BubbleSortButton("Bubble sort");
    buttons[1] = new MergeSortButton("Merge sort");
    buttons[2] = new QuickSortButton("Quick sort");

    size_t buttonPosX = ButtonsValues::buttonDistance;
    for (int i = 0; i < buttonsCount; ++i) {
        buttons[i]->setColor(Colors::orange);
        buttons[i]->setSize(ButtonsValues::buttonWidth, ButtonsValues::buttonHeight);
        buttons[i]->setPosition(buttonPosX, uiHeight - ButtonsValues::buttonDownOffset);
        buttons[i]->setName(Paths::fontFilePath, sf::Color::Black);

        buttonPosX += ButtonsValues::buttonWidth + ButtonsValues::buttonDistance;
    }
}

void UserInterface::checkButtonsClick() {
    for (size_t i = 0; i < buttonsCount; ++i) {
        if (buttons[i]->containMouse(window)) {
            buttons[i]->onClick();
            break;
        }
    }
}

void UserInterface::windowIsOpen() {
    while (window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                checkButtonsClick();
        }

        window.clear(Colors::darkPurple);
        for (int i = 0; i < buttonsCount; ++i) {
            window.draw(*buttons[i]);
        }
        window.display();
    }
}
