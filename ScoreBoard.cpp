#include "scoreboard.h"

Scoreboard::Scoreboard() : scorePlayer1(0), scorePlayer2(0) {
    if (!font.loadFromFile("./fonts/OpenSans-Regular.ttf")) {
        std::cout << "Filed to load a font"; 
    }

    textPlayer1.setFont(font);
    textPlayer1.setCharacterSize(60);
    textPlayer1.setFillColor(sf::Color::White);
    textPlayer1.setPosition(190, 20);

    textPlayer2.setFont(font);
    textPlayer2.setCharacterSize(60);
    textPlayer2.setFillColor(sf::Color::White);
    textPlayer2.setPosition(Constants::WindowWidth - 200, 20);
}

bool Scoreboard::increaseScore(bool player1) {
    if (player1) 
        scorePlayer1++;
    else 
        scorePlayer2++;
    
    return player1;
}

void Scoreboard::resetScore() {
    scorePlayer1 = 0;
    scorePlayer2 = 0;
}

void Scoreboard::draw(sf::RenderWindow& window) {
    textPlayer1.setString(std::to_string(scorePlayer1));
    textPlayer2.setString(std::to_string(scorePlayer2));

    window.draw(textPlayer1);
    window.draw(textPlayer2);
}

int Scoreboard::getScorePlayer1() const {
    return scorePlayer1;
}

int Scoreboard::getScorePlayer2() const {
    return scorePlayer2;
}