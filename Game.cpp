#include "game.h"

Game::Game() : window(sf::VideoMode(Constants::WindowWidth, Constants::WindowHeight), Constants::WindowTitle),
paddle1(10, 250), paddle2(Constants::WindowWidth - 20, 250), ball(Constants::WindowWidth / 2, Constants::WindowHeight / 2),
scoreboard(), gameState(GameState::Menu) {
    background.setFillColor(sf::Color(50, 50, 50));
    window.setFramerateLimit(60);
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (gameState == GameState::Menu) {
                gameState = GameState::Playing;
            }
            else if (gameState == GameState::GameOver) {
                resetGame();
            }
        }
    }

    if (gameState == GameState::Delay) {
        if (countdown.isFinished()) {
            gameState = GameState::Playing;
        }
    }
    if (gameState == GameState::GameOver) {
        resetGame();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (paddle1.getPosition().y > 0) {
            paddle1.move(0, -5.f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (paddle1.getPosition().y + paddle1.getPaddleSize().y < 600) {
            paddle1.move(0, 5.f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (paddle2.getPosition().y > 0) {
            paddle2.move(0, -5.f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (paddle2.getPosition().y + paddle2.getPaddleSize().y < 600) {
            paddle2.move(0, 5.f);
        }
    }
}

void Game::update() {
    countdown.update();

    if (gameState == GameState::Playing) {
        if (ball.getShape().getGlobalBounds().intersects(paddle1.getShape().getGlobalBounds()) ||
            ball.getShape().getGlobalBounds().intersects(paddle2.getShape().getGlobalBounds())) {
            ball.reverseXVelocity();
        }

        if (ball.getShape().getPosition().y <= 0 || ball.getShape().getPosition().y >= Constants::WindowHeight) {
            ball.reverseYVelocity();
        }

        if (ball.getShape().getPosition().x <= 0 || ball.getShape().getPosition().x >= Constants::WindowWidth) {
            if (ball.getShape().getPosition().x <= 0) {
                scoreboard.increaseScore(false); // Player 2 scored
            }
            else {
                scoreboard.increaseScore(true); // Player 1 scored
            }

            gameState = GameState::Delay; // Ustawienie stanu opóŸnienia
            countdown.start();
            ball.resetPosition();
        }

        // Sprawdzenie warunków zakoñczenia gry
        if (scoreboard.getScorePlayer1() >= 5 || scoreboard.getScorePlayer2() >= 5) {
            gameState = GameState::GameOver;
        }
        ball.move();
    }
}

void Game::render() {
    window.clear();

    background.draw(window);
    window.draw(paddle1.getShape());
    window.draw(paddle2.getShape());
    window.draw(ball.getShape());

    if (gameState != GameState::Menu) {
        scoreboard.draw(window);
    }

    if (gameState == GameState::Menu) {
        showMenu();
    }
    if (gameState == GameState::Delay) {
        countdown.draw(window); 
    }
    
    window.display();
}

void Game::showMenu() {


    if (!font.loadFromFile("./fonts/OpenSans-Regular.ttf")) {
        // obs³uga b³êdu ³adowania czcionki
    }

    sf::Text titleText("Network Pong", font, 50);
    titleText.setFillColor(sf::Color::White);
    titleText.setStyle(sf::Text::Bold);
    titleText.setPosition(Constants::WindowWidth / 2.0f - titleText.getLocalBounds().width / 2.0f, 50);

    sf::Text startText("Press any key to start", font, 24);
    startText.setFillColor(sf::Color::White);
    startText.setPosition(Constants::WindowWidth / 2.0f - startText.getLocalBounds().width / 2.0f, 200);

    sf::Text controlsText("Controls:\nPlayer 1: W (Up) and S (Down)\nPlayer 2: Up Arrow and Down Arrow", font, 18);
    controlsText.setFillColor(sf::Color::White);
    controlsText.setPosition(Constants::WindowWidth / 2.0f - controlsText.getLocalBounds().width / 2.0f, 300);

    window.clear(sf::Color(30, 30, 30));

    // Rysowanie tekstu menu
    window.draw(titleText);
    window.draw(startText);
    window.draw(controlsText);
}

void Game::resetGame() {

    paddle1.resetPosition(10, 250);
    paddle2.resetPosition(Constants::WindowWidth - 20, 250);
    ball.resetPosition();
    scoreboard.resetScore();
    gameState = GameState::Menu;
    delayClock.restart();
}