#include <Player.h>

void Player::init()
{
    paddle.setPosition(transform.position);
    paddle.setSize({10, 100});

    if (ID == 0)
    {
        paddle.setFillColor(sf::Color::Red);
    }
    else
    {
        paddle.setFillColor(sf::Color::Blue);
    }
}

void Player::update()
{
    paddle.setPosition(transform.position);
}

void Player::draw(sf::RenderWindow &window)
{
    window.draw(paddle);
}

void Player::input()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        transform.velocity.y = -100;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        transform.velocity.y = 100;
    else
        transform.velocity.y = 0;
}

Transform& Player::getTransform() { return transform; }
sf::Uint32& Player::getID() { return ID; }
sf::Uint32& Player::getScore() { return score; }