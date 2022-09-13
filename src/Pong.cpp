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
    player.paddle.setPosition(player.transform.position);
    player.paddle.setSize({10, 100});
    player.paddle.setFillColor(sf::Color::White);

    opponent.paddle.setFillColor(sf::Color::White);
    opponent.paddle.setSize({10, 100});
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
    sf::Packet out, in;

    out << 1 << player.ID << player.transform;

    connection.socket.send(out, connection.serverIp.value(), connection.serverPort);

    in >> opponent.transform;
}

void Pong::connect(const sf::IpAddress& _ip, unsigned short _port)
{
    connection.serverIp = _ip;
    connection.serverPort = _port;

    sf::Packet connectionPacket;
    connectionPacket << 0;    // Connection signal

    if (connection.socket.send(connectionPacket, connection.serverIp.value(), connection.serverPort) == sf::Socket::Done)
    {
        std::cout << "Connection successful!\nAwaiting info...\n";
        sf::Packet infoPacket;
        std::optional<sf::IpAddress> ip;
        if (connection.socket.receive(infoPacket, ip, connection.serverPort) == sf::Socket::Done)
        {
            infoPacket >> player.ID >> player.transform;
            std::cout << "Info received!\n";
        }
    }

    connection.socket.setBlocking(false);
}

void Pong::disconnect()
{
    sf::Packet out;
    out << 2 << player.ID;
    connection.socket.send(out, connection.serverIp.value(), connection.serverPort);
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
