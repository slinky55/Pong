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

    player.init();

    sync();

    opponent.paddle.setSize({10, 100});
    opponent.paddle.setPosition(opponent.transform.position);
    if (player.getID() == 0)
        opponent.paddle.setFillColor(sf::Color::Blue);
    else
        opponent.paddle.setFillColor(sf::Color::Red);
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
    player.update();

    opponent.paddle.setPosition(opponent.transform.position);
}

void Pong::sync()
{
    // Send our data to the server
    sf::Packet inbound, outbound;

    outbound << 0 << player.getID() << player.getTransform();
    if (connection.socket.send(outbound) != sf::Socket::Done)
        std::cout << "Failed to send data to server\n";

    // Get opponent data from the server
    if (connection.socket.receive(inbound) == sf::Socket::Done)
        inbound >> opponent.transform;
    else
        std::cout << "Failed to receive data from server\n";
}

void Pong::connect(const sf::IpAddress& _ip, unsigned short _port)
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

    connection.socket.setBlocking(false);

    std::cout << "Connection to server succeeded!\n"
                 "Awaiting info...\n";

    sf::Packet playerInfo;
    if (connection.socket.receive(playerInfo) == sf::Socket::Done)
    {
        playerInfo >> player.getTransform() >> player.getID() >> player.getScore();
        std::cout << "Received info!\n";
    }
}

void Pong::disconnect()
{
    sf::Packet packet;
    packet << -1;
    packet << player.getID();
    if (connection.socket.send(packet) == sf::Socket::Done)
    {
        connection.socket.disconnect();
        std::cout << "Disconnected from server\n";
    }
}

void Pong::EventSystem()
{
    sf::Event e{};

    while (window.pollEvent(e))
    {
        if (e.type == sf::Event::Closed)
            window.close();
    }

    player.input();
}

void Pong::PhysicsSystem(float dt)
{
    player.getTransform().position += (player.getTransform().velocity * dt);
}

void Pong::RenderSystem()
{
    window.clear(sf::Color::Black);
    player.draw(window);
    window.draw(opponent.paddle);
    window.display();
}
