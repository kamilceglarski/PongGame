#pragma once

#include <SFML/Graphics.hpp>
#include "Constants.h"

class Ball {
public:
    Ball();
    Ball(float startX, float startY);
    void move();
    void reverseXVelocity();
    void reverseYVelocity();
    sf::CircleShape getShape();
    void resetPosition(); 
    void setPosition(const sf::Vector2f& pos);
    sf::Vector2f getPosition();

private:
    sf::CircleShape shape;
    float xVelocity;
    float yVelocity;
};

