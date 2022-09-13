#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/TcpSocket.hpp>

struct Transform
{
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f scale;
    float rotation = 0;
};

struct Connection
{
    sf::IpAddress serverIpAddress {127, 0, 0, 1};
    unsigned short serverPort;
    sf::UdpSocket socket;
};