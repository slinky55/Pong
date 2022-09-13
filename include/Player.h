#include <iostream>

#include <Components.h>
#include <SFML/Graphics.hpp>

struct Player
{
    Transform transform;
    sf::Uint32 ID {0}, score {0};
    sf::RectangleShape paddle;
};