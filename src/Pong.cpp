#include "Pong.h"

Pong::~Pong()
{
    player.disconnect();
}

void Pong::init()
{
    window.create( sf::VideoMode({800, 600}), "Pong - Multiplayer" );

    player.connect(sf::IpAddress::LocalHost, 4500);
    player.init();

    sync();
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
}

void Pong::sync()
{
    // Send our data to the server

    // Get opponent data from the server
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
    window.display();
}
