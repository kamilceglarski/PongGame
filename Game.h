// game.h
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "paddle.h"
#include "ball.h"
#include "background.h"
#include "scoreboard.h"
#include "NetworkManager.h"
#include "Countdown.h"

class Game {
public:
    Game();
    void run();


private:
    enum class GameState {
        Menu,
        Playing,
        GameOver, 
        Delay
    };

    void processEvents();
    void update();
    void render();

    void showMenu();
    void resetGame();

    sf::RenderWindow window;
    Paddle paddle1;
    Paddle paddle2;
    Ball ball;
    Background background;
    Scoreboard scoreboard;
    GameState gameState;

    sf::Font font;
    sf::Clock delayClock;
    NetworkManager networkManager;
    Countdown countdown;

};

#endif // GAME_H
