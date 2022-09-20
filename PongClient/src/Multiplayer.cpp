#include <Multiplayer.h>

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

void Multiplayer::OnAwake()
{
    std::string ip, port;

    std::cout << "Enter IP: ";
    std::cin >> ip;
    std::cout << "\nEnter port: ";
    std::cin >> port;
    std::cout << "\n";

    connect(ip, std::stoi(port));

    player.paddle.setFillColor(sf::Color::White);
    player.paddle.setSize({10, 100});

    opponent.paddle.setFillColor(sf::Color::White);
    opponent.paddle.setSize({10, 100});

    ball.shape.setRadius(7.5);
    ball.shape.setPointCount(100);
    ball.shape.setFillColor(sf::Color::White);
}
void Multiplayer::OnDestroy()
{
    disconnect();
}

void Multiplayer::Input(sf::RenderWindow &_window)
{
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
void Multiplayer::Update(float dt)
{
    sync();

    // Physics
    player.transform.position += (player.transform.velocity * dt);
    opponent.transform.position += (opponent.transform.velocity * dt);

    // Update positions
    player.paddle.setPosition(player.transform.position);
    opponent.paddle.setPosition(opponent.transform.position);
    ball.shape.setPosition(ball.transform.position);
}
void Multiplayer::Draw(sf::RenderWindow &_window)
{
    _window.draw(player.paddle);
    _window.draw(opponent.paddle);
    _window.draw(ball.shape);
}

void Multiplayer::sendMessage(sf::Packet& packet)
{
    connection.socket.send(packet, connection.ip, connection.port);
}
void Multiplayer::sync()
{
    sf::Packet in;
    connection.socket.receive(in, connection.ip, connection.port);
    in >> player.transform >> opponent.transform >> ball.transform;
}
void Multiplayer::connect(const sf::IpAddress& _ip, unsigned short _port)
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
void Multiplayer::disconnect()
{
    sf::Packet out;
    out << -1 << player.ID;

    if (connection.socket.send(out, connection.ip, connection.port) == sf::Socket::Done)
    {
        std::cout << "Disconnected\n";
    }
}


