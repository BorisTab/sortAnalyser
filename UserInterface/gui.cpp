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

    buttons[0] = new BubbleSortButton;;
    buttons[1] = new MergeSortButton;

    size_t buttonPos = 30;
    for (int i = 0; i < buttonsCount; ++i) {
        buttons[i]->setColor(Colors::orange);
        buttons[i]->setSize(150, 50);

        buttons[i]->setPosition(buttonPos, uiHeight - 80);
        buttonPos += 150 + 30;
    }

    buttons[0]->setText("Bubble sort", Paths::fontFilePath, sf::Color::Black);
    buttons[1]->setText("Merge sort",  Paths::fontFilePath, sf::Color::Black);
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
