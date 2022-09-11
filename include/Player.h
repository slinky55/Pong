#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <Components.h>

class Player
{
public:
    Player() = default;

    void init();

    void update(float dt);
    void draw(sf::RenderWindow& window);

    // Network related
    void sync();
    void sendMessage(sf::Packet& _packet);
    void connect(const sf::IpAddress& _ip, unsigned short _port = 54000);
    void disconnect();
private:
    Transform transform;
    Connection connection;

    sf::RectangleShape paddle;

    sf::Uint32 score {0}, ID {0};
};