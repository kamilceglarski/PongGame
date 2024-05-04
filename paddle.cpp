#include "paddle.h"

Paddle::Paddle() {}

Paddle::Paddle(float startX, float startY) {
    shape.setSize(sf::Vector2f(paddleSize.x, paddleSize.y));
    shape.setPosition(startX, startY);
    shape.setFillColor(sf::Color::White);
}

void Paddle::move(float offsetX, float offsetY) {
    shape.move(offsetX, offsetY);
}

sf::RectangleShape Paddle::getShape() {
    return shape;
}

sf::Vector2f Paddle::getPosition()
{
    return shape.getPosition();
}

Size Paddle::getPaddleSize()
{
    return paddleSize;
}

void Paddle::resetPosition(int x, int y) {
    shape.setPosition(x, y); // Przywracamy paletkê do jej oryginalnego po³o¿enia
}

void Paddle::setPosition(const sf::Vector2f& pos)
{
    shape.setPosition(pos);
}

