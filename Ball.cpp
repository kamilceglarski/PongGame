#include "ball.h"

Ball::Ball() {
    shape.setRadius(5);
    shape.setFillColor(sf::Color::White);
    xVelocity = Constants::BallxVelocity;
    yVelocity = Constants::BallyVelocity;
}

Ball::Ball(float startX, float startY) {
    shape.setRadius(5);
    shape.setPosition(startX, startY);
    shape.setFillColor(sf::Color::White);
    xVelocity = Constants::BallxVelocity;
    yVelocity = Constants::BallyVelocity;
}

void Ball::move() {
    shape.move(xVelocity, yVelocity);
}

void Ball::reverseXVelocity() {
    xVelocity = -xVelocity;
}

void Ball::reverseYVelocity() {
    yVelocity = -yVelocity;
}

sf::CircleShape Ball::getShape() {
    return shape;
}

void Ball::resetPosition()
{
    shape.setPosition(400, 300);
}

void Ball::setPosition(const sf::Vector2f& pos)
{
    shape.setPosition(pos);
}

sf::Vector2f Ball::getPosition()
{
    return shape.getPosition();
}
