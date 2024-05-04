#include "background.h"

Background::Background() {
    backgroundRect.setSize(sf::Vector2f(800, 600)); // Ustaw rozmiar t³a na rozmiar okna
}

void Background::setFillColor(const sf::Color& color) {
    backgroundRect.setFillColor(color);
}

void Background::draw(sf::RenderWindow& window) {
    window.draw(backgroundRect);

    // Rysowanie linii przerywanej przez œrodek
    sf::VertexArray dashedLine(sf::Lines, 2);
    dashedLine[0].position = sf::Vector2f(400, 0);
    dashedLine[1].position = sf::Vector2f(400, 600);
    dashedLine[0].color = sf::Color::White;
    dashedLine[1].color = sf::Color::White;

    for (int y = 10; y < 600; y += 40) {
        dashedLine[0].position.y = y;
        dashedLine[1].position.y = y + 20;
        window.draw(dashedLine);
    }
}