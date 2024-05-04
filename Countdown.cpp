#include "Countdown.h"

#include <iostream>

Countdown::Countdown() : counting(false) { // Inicjalizacja counting na false w konstruktorze
    if (!font.loadFromFile("./fonts/OpenSans-Bold.ttf")) {
        std::cerr << "Nie mo¿na wczytaæ czcionki!" << std::endl;
    }

    countdownText.setFont(font);
    countdownText.setCharacterSize(200);
    countdownText.setFillColor(sf::Color::Blue);

 

    countdownText.setPosition(Constants::WindowWidth / 2.0f - 50, Constants::WindowHeight / 2.0f - 100);
}

bool Countdown::isFinished() {
    sf::Time elapsed = clock.getElapsedTime();
    return elapsed.asSeconds() >= 3;
}

void Countdown::update() {
    if (counting) { // Sprawdzanie, czy odliczanie jest w³¹czone
        sf::Time elapsed = clock.getElapsedTime();
        int remainingTime = 3 - static_cast<int>(elapsed.asSeconds());
        countdownText.setString(std::to_string(remainingTime));
    }
}

void Countdown::draw(sf::RenderWindow& window) {
    window.draw(countdownText);
}

void Countdown::start() {
    clock.restart(); // Restartowanie zegara
    counting = true; // Ustawianie counting na true, aby rozpocz¹æ odliczanie
}

void Countdown::stop() {
    counting = false; // Ustawianie counting na false, aby zatrzymaæ odliczanie
}