#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class Scene_B
{
public:
    Scene_B() = default;
    virtual ~Scene_B() = default;

    virtual void OnAwake() = 0;
    virtual void OnDestroy() = 0;

    virtual void Input(sf::RenderWindow& _window) = 0;
    virtual void Update(float _dt) = 0;
    virtual void Draw(sf::RenderWindow& _window) = 0;
};