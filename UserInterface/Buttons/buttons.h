//
// Created by boris on 14.09.2020.
//

#include <SFML/Graphics.hpp>
#include "../UIExceptions/uiExceptions.h"

class Button: public sf::Drawable {
public:
    void setColor(const sf::Color& color);
    void setSize(float rectWidth, float rectHeight);
    void setPosition(float x, float y);
    void setText(const char* str, const char* fontFile, const sf::Color &color);

    virtual void onClick() = 0;

    bool containMouse(const sf::Window& window);

private:
    sf::RectangleShape button;
    sf::Font font;
    sf::Text text;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setFont(const char* fontFile);
};

class BubbleSortButton: public Button {
public:
    void onClick() override;
};

class MergeSortButton: public Button {
public:
    void onClick() override;
};
