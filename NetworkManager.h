#pragma once 

#include <SFML/Network.hpp>
#include <iostream>
#include <functional>
#include <thread>
#include "paddle.h"
#include "ball.h"

class NetworkManager {
public:
    NetworkManager() {}

    void runServer(unsigned short port, std::function<void(sf::TcpSocket&)> callback);
    bool runClient(const sf::IpAddress& address, unsigned short port);
    bool send(sf::Packet& packet);
    bool receive(sf::Packet& packet);
    bool sendPaddlePosition(const sf::Vector2f& position);
    bool sendBallPosition(const sf::Vector2f& position);

private:
    sf::TcpSocket socket;
    sf::TcpListener listener;
    bool isServer = false;
    bool isConnected = false;
    std::thread serverThread;

    void handleServer(unsigned short port, std::function<void(sf::TcpSocket&)> callback);
    bool handleClient(const sf::IpAddress& address, unsigned short port);

};