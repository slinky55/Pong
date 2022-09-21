
/*
MIT License

Copyright (c) 2022 slinky55

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Scenes/Menu.h"

#include "SceneManager.h"

void Menu::OnAwake()
{
    m_selected = false;

    m_font.loadFromFile("res/fonts/Pixeboy.ttf");

    m_singleplayer.setSize({300, 50});
    m_singleplayer.setOrigin({m_singleplayer.getSize().x / 2, m_singleplayer.getSize().y / 2});
    m_singleplayer.setPosition({400, 200});
    m_singleplayer.setFillColor({0, 0, 171, 125});
    m_singleText.setCharacterSize(24);
    m_singleText.setFont(m_font);
    m_singleText.setString("Singleplayer");
    m_singleText.setOrigin(m_singleText.getLocalBounds().width/2, m_singleText.getLocalBounds().height/2);
    m_singleText.setPosition( m_singleplayer.getGlobalBounds().left + (m_singleplayer.getSize().x / 2),
                             (m_singleplayer.getGlobalBounds().top + (m_singleplayer.getSize().y / 4)) );

    m_multiplayer.setSize({300, 50});
    m_multiplayer.setOrigin({m_singleplayer.getSize().x / 2, m_singleplayer.getSize().y / 2});
    m_multiplayer.setPosition({400, 300});
    m_multiplayer.setFillColor({171, 0, 0, 125});
    m_multiText.setCharacterSize(24);
    m_multiText.setFont(m_font);
    m_multiText.setString("Multiplayer");
    m_multiText.setOrigin(m_multiText.getLocalBounds().width/2, m_multiText.getLocalBounds().height/2);
    m_multiText.setPosition(m_multiplayer.getGlobalBounds().left + (m_multiplayer.getSize().x / 2),
                            m_multiplayer.getGlobalBounds().top + (m_multiplayer.getSize().y / 4));

    m_title.setCharacterSize(64);
    m_title.setFont(m_font);
    m_title.setString("PONG");
    m_title.setPosition({400 - (m_title.getLocalBounds().width / 2), 50});

    left.transform = {
            {10, 275},
            {0, 0},
            {1, 1},
            0
    };

    right.transform = {
            {780, 25},
            {0, 0},
            {1, 1},
            0
    };

    ball.transform = {
            {400, 300},
            {-200, 200},
            {1, 1},
            0
    };

    left.paddle.setPosition(left.transform.position);
    left.paddle.setSize({10, 100});
    left.paddle.setFillColor(sf::Color::White);

    right.paddle.setPosition(right.transform.position);
    right.paddle.setSize({10, 100});
    right.paddle.setFillColor(sf::Color::White);

    ball.shape.setRadius(7.5);
    ball.shape.setFillColor(sf::Color::White);
    ball.shape.setPointCount(100);
    ball.shape.setPosition(ball.transform.position);
}

void Menu::OnDestroy()
{

}

void Menu::Update(float _dt)
{
    if (ball.transform.velocity.x < 0)
    {
        right.transform.velocity.y = 0;
        switch(AISystem(left))
        {
            case Command::UP:
                left.transform.velocity.y = -300;
                break;
            case Command::DOWN:
                left.transform.velocity.y = 300;
                break;
            case Command::STOP:
                left.transform.velocity.y = 0;
                break;
        }
    }
    else
    {
        left.transform.velocity.y = 0;
        switch (AISystem(right))
        {
            case Command::UP:
                right.transform.velocity.y = -300;
                break;
            case Command::DOWN:
                right.transform.velocity.y = 300;
                break;
            case Command::STOP:
                right.transform.velocity.y = 0;
                break;
        }
    }

    DetectCollisions();

    left.transform.position += (left.transform.velocity * _dt);
    right.transform.position += (right.transform.velocity * _dt);
    ball.transform.position += (ball.transform.velocity * _dt);

    left.paddle.setPosition(left.transform.position);
    right.paddle.setPosition(right.transform.position);
    ball.shape.setPosition(ball.transform.position);
}

void Menu::Draw(sf::RenderWindow &_window)
{
    _window.draw(left.paddle);
    _window.draw(right.paddle);
    _window.draw(ball.shape);

    _window.draw(m_title);

    _window.draw(m_singleplayer);
    _window.draw(m_multiplayer);

    _window.draw(m_singleText);
    _window.draw(m_multiText);
}

void Menu::Input(sf::RenderWindow &_window)
{
    if (m_singleplayer.getGlobalBounds().contains(sf::Mouse::getPosition(_window).x,
                                                  sf::Mouse::getPosition(_window).y) &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left) && !m_selected)
    {
        SceneManager::Instance()->SetCurrentScene("singleplayer");
        m_selected = true;
    }
    else if (m_multiplayer.getGlobalBounds().contains(sf::Mouse::getPosition(_window).x,
                                                       sf::Mouse::getPosition(_window).y) &&
             sf::Mouse::isButtonPressed(sf::Mouse::Left) && !m_selected)
    {
        SceneManager::Instance()->SetCurrentScene("multiplayer");
        m_selected = true;
    }
}

void Menu::ResetBall()
{
    ball.transform.position = {400, 300};
    ball.transform.velocity.x *= -1;
    ball.transform.velocity.y *= -1;
}

void Menu::DetectCollisions()
{
    Transform& ballT = ball.transform;
    Transform& playerT = left.transform;
    Transform& oppT = right.transform;

    // Window collisions
    if (ballT.position.x <= 0)  // Opponent scores
    {
        ResetBall();
    }
    if (ballT.position.x + (ball.shape.getRadius()*2) >= 800) // Player Score
    {
        ResetBall();
    }

    if (ballT.position.y <= 0)
    {
        ballT.position.y = 1;
        ballT.velocity.y *= -1;
    }

    if (ballT.position.y + (ball.shape.getRadius()*2) >= 600)
    {
        ballT.position.y = 600 - ((ball.shape.getRadius()*2) + 1);
        ballT.velocity.y *= -1;
    }

    bool hitPlayer {(ballT.position.y >= playerT.position.y &&
                     ballT.position.y + (ball.shape.getRadius()*2) <= playerT.position.y + left.paddle.getSize().y)
                    &&
                    ballT.position.x <= playerT.position.x + left.paddle.getSize().x && ballT.position.x >= playerT.position.x};

    bool hitOpp {(ballT.position.y >= oppT.position.y &&
                  ballT.position.y + (ball.shape.getRadius()*2) <= oppT.position.y + right.paddle.getSize().y)
                 &&
                 ballT.position.x + (ball.shape.getRadius()*2) >= oppT.position.x && ballT.position.x + (ball.shape.getRadius()*2) <= oppT.position.x + right.paddle.getSize().x};

    if (hitPlayer || hitOpp)
        ballT.velocity.x *= -1;
}

Command Menu::AISystem(Player& player) const
{
    if (ball.transform.position.y <
            player.transform.position.y)
        return Command::UP;
    else if (ball.transform.position.y >
            player.transform.position.y + player.paddle.getSize().y)
        return Command::DOWN;
    return Command::STOP;
}
