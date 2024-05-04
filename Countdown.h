#pragma once

#include <SFML/Graphics.hpp>
#include "Constants.h"

class Countdown {
private:
    sf::Text countdownText;
    sf::Clock clock;
    sf::Font font;
    bool counting; // Dodanie zmiennej boolowskiej do �ledzenia stanu odliczania

public:
    Countdown();
    bool isFinished();
    void update();
    void draw(sf::RenderWindow& window);
    void start(); // Metoda rozpoczynaj�ca odliczanie
    void stop(); // Metoda zatrzymuj�ca odliczanie
};