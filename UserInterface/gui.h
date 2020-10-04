//
// Created by boris on 09.09.2020.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Buttons/buttons.h"

class UserInterface {
public:
    UserInterface();
    UserInterface(size_t uiWidth, size_t uiHeight);

    void  windowIsOpen();

    ~UserInterface();
private:
    const size_t uiWidth = 1200;
    const size_t uiHeight = 600;
    sf::RenderWindow window;
    const size_t buttonsCount = 2;

    Button** buttons = nullptr;

    void makeButtons();

    void checkButtonsClick();
};