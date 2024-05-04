#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "constants.h"

class Scoreboard {
public:
    Scoreboard();
    bool increaseScore(bool player1);
    void resetScore();
    void draw(sf::RenderWindow& window);

    int getScorePlayer1() const;
    int getScorePlayer2() const;

private:
    int scorePlayer1;
    int scorePlayer2;
    sf::Font font;
    sf::Text textPlayer1;
    sf::Text textPlayer2;
};
