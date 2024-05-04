#include "NetworkManager.h"

void NetworkManager::runServer(unsigned short port, std::function<void(sf::TcpSocket&)> callback) {
    if (isServer) return;
    isServer = true;

    serverThread = std::thread(&NetworkManager::handleServer, this, port, callback);
}

bool NetworkManager::runClient(const sf::IpAddress& address, unsigned short port) {
    if (isConnected) return true;
    isConnected = handleClient(address, port);
    return isConnected;
}

bool NetworkManager::send(sf::Packet& packet) {
    if (!isConnected) return false;
    return socket.send(packet) == sf::Socket::Done;
}

bool NetworkManager::receive(sf::Packet& packet) {
    if (!isConnected) return false;
    return socket.receive(packet) == sf::Socket::Done;
}

bool NetworkManager::sendPaddlePosition(const sf::Vector2f& position) {
    sf::Packet packet;
    packet << position.x << position.y;
    return send(packet);
}

bool NetworkManager::sendBallPosition(const sf::Vector2f& position) {
    sf::Packet packet;
    packet << position.x << position.y;
    return send(packet);
}

void NetworkManager::handleServer(unsigned short port, std::function<void(sf::TcpSocket&)> callback) {
    if (listener.listen(port) != sf::Socket::Done) {
        std::cerr << "Error listening on port " << port << std::endl;
        return;
    }

    sf::TcpSocket clientSocket;
    if (listener.accept(clientSocket) != sf::Socket::Done) {
        std::cerr << "Error accepting connection." << std::endl;
        return;
    }

    callback(clientSocket);
}

bool NetworkManager::handleClient(const sf::IpAddress& address, unsigned short port) {
    if (socket.connect(address, port) != sf::Socket::Done) {
        std::cerr << "Error connecting to server." << std::endl;
        return false;
    }
    return true;
}