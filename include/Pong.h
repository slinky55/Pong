#pragma once

#include <Player.h>
#include <Components.h>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

class Pong {
public:
    Pong() = default;
    ~Pong();

    void init();
    void run();

private:
    Player player;
    Player opponent;
    Connection connection;

    sf::RenderWindow window;
    sf::Clock clock;

    void update();

    // Network "Systems"
    void sync();
    void connect(const sf::IpAddress& _ip, unsigned short _port);
    void disconnect();

    // Game "Systems"
    void EventSystem();
    void PhysicsSystem(float dt);
    void RenderSystem();
};
