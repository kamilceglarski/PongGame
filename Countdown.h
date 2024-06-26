#pragma once

#include <SFML/Graphics.hpp>
#include "Constants.h"

class Countdown {
private:
    sf::Text countdownText;
    sf::Clock clock;
    sf::Font font;
    bool counting; // Dodanie zmiennej boolowskiej do śledzenia stanu odliczania

public:
    Countdown();
    bool isFinished();
    void update();
    void draw(sf::RenderWindow& window);
    void start(); // Metoda rozpoczynająca odliczanie
    void stop(); // Metoda zatrzymująca odliczanie
};