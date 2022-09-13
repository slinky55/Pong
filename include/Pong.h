#pragma once

#include <Player.h>

class Pong {
public:
    Pong() = default;
    ~Pong();

    void init();
    void run();

private:
    Player player;

    struct Opponent
    {
        sf::RectangleShape paddle;
        Transform transform;
        sf::Uint32 score {0}, ID {0};
    } opponent;

    // The ball will be synced across both clients
    struct Ball
    {
        Transform transform;
        sf::CircleShape circle;
    } ball;

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
