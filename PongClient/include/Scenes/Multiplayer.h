#pragma once

#include "Scene.h"
#include <SFML/Network.hpp>
#include "Player.h"

class Multiplayer : public Scene_B
{
public:
    Multiplayer() = default;

    void OnAwake() override;
    void OnDestroy() override;

    void Input(sf::RenderWindow& _window) override;
    void Update(float _dt) override;
    void Draw(sf::RenderWindow& _window) override;
private:
    NetPlayer player;
    Player opponent;

    Connection connection;

    struct Ball
    {
        Transform transform;
        sf::CircleShape shape;
    } ball;

    //Network "Systems"
    void sendMessage(sf::Packet& packet);
    void sync();
    void connect(const sf::IpAddress& _ip, unsigned short _port);
    void disconnect();
};