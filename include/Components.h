#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Network/IpAddress.hpp>
#include "SFML/Network/UdpSocket.hpp"

enum class Signal {
    CONNECT = 0,
    SYNC,
    DISCONNECT
};

struct Transform
{
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f scale;
    float rotation = 0;
};

struct Connection
{
    std::optional<sf::IpAddress> serverIp;
    unsigned short serverPort = 4500;
    sf::UdpSocket socket;
};