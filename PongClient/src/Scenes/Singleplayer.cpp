#include <Scenes/Singleplayer.h>

void Singleplayer::OnAwake()
{
    player.transform = {
            {10, 250},
            {0, 0},
            {1, 1},
            0
    };

    opponent.transform = {
            {780, 250},
            {0, 0},
            {1, 1},
            0
    };

    ball.transform = {
            {400, 300},
            {-175, 175},
            {1, 1},
            0
    };

    player.paddle.setPosition(player.transform.position);
    player.paddle.setSize({10, 100});
    player.paddle.setFillColor(sf::Color::White);

    opponent.paddle.setPosition(opponent.transform.position);
    opponent.paddle.setSize({10, 100});
    opponent.paddle.setFillColor(sf::Color::White);

    ball.shape.setRadius(7.5);
    ball.shape.setFillColor(sf::Color::White);
    ball.shape.setPointCount(100);
    ball.shape.setPosition(ball.transform.position);
}

void Singleplayer::OnDestroy()
{

}

void Singleplayer::Input(sf::RenderWindow &_window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player.transform.velocity.y = -200;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player.transform.velocity.y = 200;
    }
    else
    {
        player.transform.velocity.y = 0;
    }
}

void Singleplayer::Update(float _dt)
{
    switch (AISystem())
    {
        case Command::UP:
            opponent.transform.velocity.y = -200;
            break;
        case Command::DOWN:
            opponent.transform.velocity.y = 200;
            break;
        case Command::STOP:
            opponent.transform.velocity.y = 0;
            break;
    }

    DetectCollisions();

    player.transform.position += (player.transform.velocity * _dt);
    opponent.transform.position += (opponent.transform.velocity * _dt);
    ball.transform.position += (ball.transform.velocity * _dt);

    player.paddle.setPosition(player.transform.position);
    opponent.paddle.setPosition(opponent.transform.position);
    ball.shape.setPosition(ball.transform.position);
}

void Singleplayer::Draw(sf::RenderWindow &_window)
{
    _window.draw(player.paddle);
    _window.draw(opponent.paddle);
    _window.draw(ball.shape);
}

void Singleplayer::ResetBall()
{
    ball.transform.position = {400, 300};
    ball.transform.velocity.x *= -1;
    ball.transform.velocity.y *= -1;
}

void Singleplayer::DetectCollisions()
{
    Transform& ballT = ball.transform;
    Transform& playerT = player.transform;
    Transform& oppT = opponent.transform;

    // Window collisions
    if (ballT.position.x <= 0)  // Opponent scores
    {
        ResetBall();
    }
    if (ballT.position.x + ball.shape.getRadius() >= 800) // Player Score
    {
        ResetBall();
    }

    if (ballT.position.y <= 0
        || ballT.position.y + ball.shape.getRadius() >= 600)
        ballT.velocity.y *= -1;

    bool hitPlayer {(ballT.position.y >= playerT.position.y &&
                    ballT.position.y + ball.shape.getRadius() <= playerT.position.y + player.paddle.getSize().y)
                    &&
                    ballT.position.x <= playerT.position.x + player.paddle.getSize().x && ballT.position.x >= playerT.position.x};

    bool hitOpp {(ballT.position.y >= oppT.position.y &&
                  ballT.position.y + ball.shape.getRadius() <= oppT.position.y + opponent.paddle.getSize().y)
                 &&
                 ballT.position.x + (ball.shape.getRadius()*2) >= oppT.position.x && ballT.position.x + (ball.shape.getRadius()*2) <= oppT.position.x + opponent.paddle.getSize().x};

    if (hitPlayer || hitOpp)
        ballT.velocity.x *= -1;
}

Command Singleplayer::AISystem() const
{
    if (ball.transform.position.y <
    opponent.transform.position.y)
        return Command::UP;
    else if (ball.transform.position.y >
            opponent.transform.position.y + opponent.paddle.getSize().y)
        return Command::DOWN;
    return Command::STOP;
}