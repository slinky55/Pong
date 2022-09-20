#pragma once

#include <Scene.h>
#include <Player.h>

class Singleplayer : public Scene_B
{
public:
    Singleplayer() = default;

    void OnAwake() override;
    void OnDestroy() override;

    void Input(sf::RenderWindow& _window) override;
    void Update(float _dt) override;
    void Draw(sf::RenderWindow& _window) override;
private:
    Player player;
    Player opponent;

    struct Ball
    {
        Transform transform;
        sf::CircleShape shape;
    } ball;

    void ResetBall();
    void DetectCollisions();
    Command AISystem() const;
};
