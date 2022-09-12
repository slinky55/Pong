#pragma once

#include <Player.h>
#include <Ball.h>

class Pong {
public:
    Pong() = default;
    ~Pong();

    void init();
    void run();

private:
    Player player;

    // The ball will be synced across both clients
    Ball ball;

    sf::RenderWindow window;

    sf::Clock clock;

    void update();
    void sync();

    // Game "Systems"
    void EventSystem();
    void PhysicsSystem(float dt);
    void RenderSystem();
};
