#include <iostream>

#include <Components.h>
#include <SFML/Graphics.hpp>

struct Player
{
    Transform transform;
    uint32_t score {0};
    sf::RectangleShape paddle;
};

struct NetPlayer : public Player
{
    uint32_t ID;
};