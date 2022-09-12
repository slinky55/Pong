#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <Components.h>

class Player
{
public:
    Player() = default;

    void init();

    void update();
    void draw(sf::RenderWindow& window);

    void input();

    // Network related
    void connect(const sf::IpAddress& _ip, unsigned short _port = 54000);
    void disconnect();

    // Accessors
    Transform& getTransform();
private:
    Transform transform;
    Connection connection;

    sf::RectangleShape paddle;

    sf::Uint32 score {0}, ID {0};
};