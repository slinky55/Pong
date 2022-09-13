#include "Pong.h"

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

Pong::~Pong()
{
    disconnect();
}

void Pong::init()
{
    window.create( sf::VideoMode({800, 600}), "Pong - Multiplayer" );

    connect(sf::IpAddress::LocalHost, 4500);

    sync();

    player.paddle.setFillColor(sf::Color::White);
    opponent.paddle.setFillColor(sf::Color::White);
}

void Pong::run()
{
    while (window.isOpen())
    {
        EventSystem();
        PhysicsSystem(clock.restart().asSeconds());
        update();
        RenderSystem();
        sync();
    }
}

void Pong::update()
{
    player.paddle.setPosition(player.transform.position);
    opponent.paddle.setPosition(opponent.transform.position);
}

void Pong::sync()
{

}

void Pong::connect(const sf::IpAddress& _ip, unsigned short _port)
{
    connection.serverIpAddress = _ip;
    connection.serverPort = _port;


}

void Pong::disconnect()
{

}

void Pong::EventSystem()
{
    sf::Event e{};

    while (window.pollEvent(e))
    {
        if (e.type == sf::Event::Closed)
            window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        player.transform.velocity.y = -75;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        player.transform.velocity.y = 75;
}

void Pong::PhysicsSystem(float dt)
{
    player.transform.position += (player.transform.velocity * dt);
}

void Pong::RenderSystem()
{
    window.clear(sf::Color::Black);

    // TODO: Draw UI

    window.draw(player.paddle);
    window.draw(opponent.paddle);

    window.display();
}
