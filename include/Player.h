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

    // Accessors
    Transform& getTransform();
    sf::Uint32& getID();
    sf::Uint32& getScore();
private:
    Transform transform;

    sf::RectangleShape paddle;

    sf::Uint32 score {0}, ID {0};
};