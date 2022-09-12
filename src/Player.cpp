#include <Player.h>

sf::Packet& operator<<(sf::Packet& packet, const sf::Vector2f& vec)
{
    return packet << vec.x << vec.y;
}

sf::Packet& operator>>(sf::Packet& packet, sf::Vector2f& vec)
{
    return packet >> vec.x >> vec.y;
}

sf::Packet& operator<<(sf::Packet& packet, const Transform& transform)
{
    return packet << transform.position << transform.velocity << transform.scale << transform.rotation;
}

sf::Packet& operator>>(sf::Packet& packet, Transform& transform)
{
    return packet >> transform.position >> transform.velocity >> transform.scale >> transform.rotation;
}

void Player::init()
{
    paddle.setPosition(transform.position);
    paddle.setSize({10, 100});
    paddle.setFillColor(sf::Color::White);
}

void Player::update()
{
    paddle.setPosition(transform.position);
}

void Player::draw(sf::RenderWindow &window)
{
    window.draw(paddle);
}

void Player::input()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        transform.velocity.y = -100;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        transform.velocity.y = 100;
    else
        transform.velocity.y = 0;
}

void Player::connect(const sf::IpAddress& _ip, unsigned short _port)
{
    connection.serverIpAddress = _ip;
    connection.serverPort = _port;

    sf::Socket::Status connectionStatus = connection.socket.connect(
            connection.serverIpAddress, connection.serverPort, sf::seconds(5));

    if (connectionStatus != sf::Socket::Done)
    {
        std::cout << "Failed to connect to server!\n";
        return;
    }

    std::cout << "Connection to server succeeded!\n"
                 "Awaiting info...\n";

    sf::Packet playerInfo;
    if (connection.socket.receive(playerInfo) == sf::Socket::Done)
    {
        playerInfo >> transform >> ID >> score;
        std::cout << "Received info!\n";
        init();
    }
}

void Player::disconnect()
{
    sf::Packet packet;
    packet << -1;
    packet << ID;
    if (connection.socket.send(packet) == sf::Socket::Done)
    {
        connection.socket.disconnect();
        std::cout << "Disconnected from server\n";
    }
}

Transform& Player::getTransform() { return transform; }