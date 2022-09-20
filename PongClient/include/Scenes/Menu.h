#include <Scene.h>

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

    sf::Text m_singleText;
    sf::Text m_multiText;

    bool m_selected = false;
};