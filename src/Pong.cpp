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

Pong::Pong() = default;
Pong::~Pong()
{
    disconnect();
}

void Pong::init(const std::string& ip, unsigned short port = 4500)
{
    window.create( sf::VideoMode({800, 600}), "Pong - Multiplayer" );
    connect(ip, port);

    player.paddle.setFillColor(sf::Color::White);
    player.paddle.setSize({10, 100});

    opponent.paddle.setFillColor(sf::Color::White);
    opponent.paddle.setSize({10, 100});
}

void Pong::run()
{
    while (window.isOpen())
    {
        sync();
        EventSystem();
        //PhysicsSystem(clock.restart().asSeconds());
        update();
        RenderSystem();
    }
}

void Pong::update()
{
    player.paddle.setPosition(player.transform.position);
    opponent.paddle.setPosition(opponent.transform.position);
    //ball.shape.setPosition(ball.transform.position);
}

void Pong::sync()
{
    sf::Packet in;
    connection.socket.receive(in, connection.ip, connection.port);
    in >> player.transform >> opponent.transform;
}

void Pong::connect(const sf::IpAddress& _ip, unsigned short _port)
{
    sf::Packet out;
    out << 0;
    
    if (connection.socket.send(out, _ip, _port) == sf::Socket::Done)
    {
        connection.ip = _ip;
        connection.port = _port;   

        sf::Packet in;
        // Declare these for now, just so our connection doesn't get overwriten
        // in case of a different sender
        sf::IpAddress ip;
        unsigned short port;
        if (connection.socket.receive(in, ip, port) == sf::Socket::Done)
        {
            in >> player.ID >> player.transform;
            std::cout << player.transform.position.x << ":" << player.transform.position.y << "\n";
            std::cout << "Connection successful!\nID: " << player.ID << "\n";
            connection.socket.setBlocking(false);
        }
    }
}

void Pong::disconnect()
{
    sf::Packet out;
    out << -1 << player.ID;

    if (connection.socket.send(out, connection.ip, connection.port) == sf::Socket::Done)
    {
        std::cout << "Disconnected\n";
    }
}

void Pong::sendMessage(sf::Packet& packet)
{
    connection.socket.send(packet, connection.ip, connection.port);
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
    {
        sf::Packet cmd;
        cmd << 1 << player.ID << 0;
        sendMessage(cmd);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sf::Packet cmd;
        cmd << 1 << player.ID << 1;
        sendMessage(cmd);
    }
    else
    {
        sf::Packet cmd;
        cmd << 1 << player.ID << -1;
        sendMessage(cmd);
    }
}

void Pong::PhysicsSystem(float dt)
{
    player.transform.position += (player.transform.velocity * dt);
    opponent.transform.position += (opponent.transform.velocity * dt);
}

void Pong::RenderSystem()
{
    window.clear();

    // TODO: Draw UI

    window.draw(player.paddle);
    window.draw(opponent.paddle);
    //window.draw(ball.shape);

    window.display();
}
