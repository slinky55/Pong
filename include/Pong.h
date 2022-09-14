#pragma once

#include <Player.h>
#include <Components.h>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

class Pong {
public:
    Pong();
    ~Pong();

    void init(const std::string& ip, unsigned short port);
    void run();

private:
    Player player;
    Player opponent;

    struct Ball
    {
        Transform transform;
        sf::CircleShape shape;
    } ball;
    
    Connection connection;

    sf::RenderWindow window;
    sf::Clock clock;

    void update();

    // Network "Systems"
    void sendMessage(sf::Packet& packet);
    void sync();
    void connect(const sf::IpAddress& _ip, unsigned short _port);
    void disconnect();

    // Game "Systems"
    void EventSystem();
    void PhysicsSystem(float dt);
    void RenderSystem();
};
