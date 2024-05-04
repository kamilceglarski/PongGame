#pragma once

#include <SFML/Graphics.hpp>

struct Size {
    const int x;
    const int y;
};

class Paddle {
public:
    Paddle();
    Paddle(float startX, float startY);
    void move(float offsetX, float offsetY);
    sf::RectangleShape getShape();
    sf::Vector2f getPosition();
    Size getPaddleSize(); 
    void resetPosition(int x, int y); // Dodajemy metodê resetowania po³o¿enia paletki
    void setPosition(const sf::Vector2f& pos);

private:
    sf::RectangleShape shape;
    Size paddleSize{ 10,60 };
    
};
