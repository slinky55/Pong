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


#include "Scene.h"
#include "Player.h"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Mouse.hpp>

#include <iostream>

class Menu : public Scene_B
{
public:
    Menu() = default;

    void OnAwake() override;
    void OnDestroy() override;

    void Input(sf::RenderWindow& _window) override;
    void Update(float _dt) override;
    void Draw(sf::RenderWindow& _window) override;

private:
    sf::Font m_font;

    sf::RectangleShape m_singleplayer;
    sf::RectangleShape m_multiplayer;

    sf::Text m_title;
    sf::Text m_singleText;
    sf::Text m_multiText;

    bool m_selected = false;

    // "Game" Stuff
    Player left;
    Player right;

    struct Ball
    {
        Transform transform;
        sf::CircleShape shape;
    } ball;

    void ResetBall();
    void DetectCollisions();
    Command AISystem(Player& player) const;
};