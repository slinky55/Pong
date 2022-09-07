#include <iostream>
#include <SFML/Graphics.hpp>

const float PADDLE_VELOCITY = 250.f;
const sf::Vector2f BALL_ORIGIN {400, 300};

enum class Input {
    Up, Down, Stop
};

struct GameState {
    sf::RenderWindow window;

    sf::Vector2f playerPos;
    sf::Vector2f playerVelocity;

    sf::Vector2f cpuPos;
    sf::Vector2f cpuVelocity;

    sf::Vector2f ballPos;
    sf::Vector2f ballVelocity = {200, 200};

    int playerScore {0}, cpuScore {0};

    sf::RectangleShape playerPaddle;
    sf::RectangleShape cpuPaddle;
    sf::CircleShape ball;
};

Input AISystem(GameState& state)
{ 

}

bool intersect(const sf::Vector2f& pointA,
               const sf::Vector2f& pointB,
               const sf::Vector2f& pointC,
               const sf::Vector2f& pointD)
{
    float t, u;
    float dem = ( (pointA.x - pointB.x)*(pointC.y - pointD.y) - (pointA.y - pointB.y)*(pointC.x - pointD.x) );

    t = ( ((pointA.x - pointC.x)*(pointC.y - pointD.y) -  (pointA.y - pointC.y)*(pointC.x - pointD.x)) / dem);
    u = ( ((pointA.x - pointB.x)*(pointA.y - pointC.y) -  (pointA.y - pointB.y)*(pointA.x - pointC.x)) / dem);

    if ( (t >= 0 && t <= 1) && (u >= 0 && u <= 1) )
        return true;
    return false;
}

void Update(GameState &state, Input player, Input cpu) {
    switch (player) {
        case Input::Up:
            state.playerVelocity = {0, -PADDLE_VELOCITY};
            break;
        case Input::Down:
            state.playerVelocity = {0, PADDLE_VELOCITY};
            break;
        case Input::Stop:
            state.playerVelocity = {0, 0};
            break;
    }
    switch (cpu)
    {
        case Input::Up:
            state.cpuVelocity = {0, -PADDLE_VELOCITY};
            break;
        case Input::Down:
            state.cpuVelocity = {0, PADDLE_VELOCITY};
            break;
        case Input::Stop:
            state.cpuVelocity = {0, 0};
            break;
    }
}

void PhysicsSystem(GameState &state, float deltaTime) {
    state.playerPos += (state.playerVelocity * deltaTime);
    state.playerPaddle.setPosition(state.playerPos);

    state.cpuPos += (state.cpuVelocity * deltaTime);
    state.cpuPaddle.setPosition(state.cpuPos);

    sf::Vector2f lastBallPos = state.ballPos;
    state.ballPos += (state.ballVelocity * deltaTime);
    state.ball.setPosition(state.ballPos);

    // Paddle-window Collisions
    if (state.playerPos.y < 0)
        state.playerPos.y = 0;
    else if (state.playerPos.y >= state.window.getSize().y - state.playerPaddle.getSize().y)
        state.playerPos.y = state.window.getSize().y - state.playerPaddle.getSize().y;

    if (state.cpuPos.y < 0)
        state.cpuPos.y = 0;
    else if (state.cpuPos.y >= state.window.getSize().y - state.cpuPaddle.getSize().y)
        state.cpuPos.y = state.window.getSize().y - state.cpuPaddle.getSize().y;

    // Ball-window collisions
    if (state.ballPos.x < 0)
    {
        state.ballPos = BALL_ORIGIN;
        state.ballVelocity.x *= -1;
    }
    else if (state.ballPos.x + state.ball.getRadius() * 2 > state.window.getSize().x)
    {
        state.ballPos = BALL_ORIGIN;
        state.ballVelocity.x *= -1;
    }
    else if (state.ballPos.y < 0)
        state.ballVelocity.y *= -1;
    else if (state.ballPos.y + state.ball.getRadius() * 2 > state.window.getSize().y)
        state.ballVelocity.y *= -1;

    // Ball-paddle collisions

    // TODO: Fix line intersection method for collision

    /*if (intersect(lastBallPos,
                  state.ballPos,
                  sf::Vector2f(state.playerPos.x + state.playerPaddle.getSize().x, state.playerPos.y),
                  sf::Vector2f(state.playerPos.x + state.playerPaddle.getSize().x, state.playerPos.y + state.playerPaddle.getSize().y)) && state.ballVelocity.x < 0) {
        std::cout << "hit";
        state.ballVelocity.x *= -1;
    } else if (intersect(lastBallPos,
                state.ballPos,
                sf::Vector2f(),
                sf::Vector2f())) {
//        state.ballVelocity.x *= -1;
    }*/

    if (state.ballPos.x <= state.playerPos.x + state.playerPaddle.getSize().x &&
        state.ballPos.y >= state.playerPos.y &&
        state.ballPos.y + state.ball.getRadius()*2 <= state.playerPos.y + state.playerPaddle.getSize().y)
    {
        state.ballVelocity.x *= -1;
    }
    else if (state.ballPos.x + state.ball.getRadius()*2 >= state.cpuPos.x &&
             state.ballPos.y >= state.cpuPos.y &&
             state.ballPos.y + state.ball.getRadius()*2 <= state.playerPos.y + state.playerPaddle.getSize().y)
    {
        state.ballVelocity.x *= -1;
    }
}

void RenderSystem(GameState &state) {
    state.window.clear(sf::Color::Black);

    state.window.draw(state.playerPaddle);
    state.window.draw(state.cpuPaddle);
    state.window.draw(state.ball);

    state.window.display();
}

void PollInput(GameState &state) {
    // Window events
    sf::Event e{};
    while (state.window.pollEvent(e))
        if (e.type == sf::Event::Closed)
            state.window.close();

    Input player, cpu;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        player = Input::Up;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        player = Input::Down;
    else
        player = Input::Stop;

    cpu = AISystem(state);

    // User input
    Update(state, player, cpu);
}

void Run(GameState &state) {
    sf::Clock clock;
    while (state.window.isOpen()) {
        // Logic
        PollInput(state);
        PhysicsSystem(state, clock.restart().asSeconds());
        RenderSystem(state);
    }
}

void Init(GameState &state) {
    state.window.create(sf::VideoMode{{800, 600}}, "Pong");

    state.playerPos = {0, 250};
    state.playerPaddle.setPosition({0, 250});
    state.playerPaddle.setSize({10, 100});
    state.playerPaddle.setFillColor(sf::Color::White);

    state.cpuPos = {800 - 10, 250};
    state.cpuPaddle.setPosition({800 - 10, 250});
    state.cpuPaddle.setSize({10, 100});
    state.cpuPaddle.setFillColor(sf::Color::White);

    state.ballPos = {400, 300};
    state.ball.setPosition({400, 300});
    state.ball.setRadius(7.5f);
    state.ball.setFillColor(sf::Color::White);
}

int main() {
    GameState state;

    Init(state);
    Run(state);

    return 0;
}
