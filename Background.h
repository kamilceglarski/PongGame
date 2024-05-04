#pragma once

#include <SFML/Graphics.hpp>

class Background {
public:
    Background();
    void setFillColor(const sf::Color& color);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape backgroundRect;
};
