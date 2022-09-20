#include "Scenes/Menu.h"

#include <SceneManager.h>

void Menu::OnAwake()
{
    m_selected = false;

    m_font.loadFromFile("res/fonts/Roboto-Regular.ttf");

    m_singleplayer.setSize({300, 50});
    m_singleplayer.setOrigin({m_singleplayer.getSize().x / 2, m_singleplayer.getSize().y / 2});
    m_singleplayer.setPosition({400, 200});
    m_singleplayer.setFillColor({0, 0, 171, 125});
    m_singleText.setCharacterSize(24);
    m_singleText.setFont(m_font);
    m_singleText.setString("Singleplayer");
    m_singleText.setOrigin(m_singleText.getLocalBounds().width/2, m_singleText.getLocalBounds().height/2);
    m_singleText.setPosition(m_singleplayer.getGlobalBounds().left + (m_singleplayer.getSize().x / 2),
                             m_singleplayer.getGlobalBounds().top + (m_singleplayer.getSize().y / 2));

    m_multiplayer.setSize({300, 50});
    m_multiplayer.setOrigin({m_singleplayer.getSize().x / 2, m_singleplayer.getSize().y / 2});
    m_multiplayer.setPosition({400, 300});
    m_multiplayer.setFillColor({171, 0, 0, 125});
    m_multiText.setCharacterSize(24);
    m_multiText.setFont(m_font);
    m_multiText.setString("Multiplayer");
    m_multiText.setOrigin(m_multiText.getLocalBounds().width/2, m_multiText.getLocalBounds().height/2);
    m_multiText.setPosition(m_multiplayer.getGlobalBounds().left + (m_multiplayer.getSize().x / 2),
                            m_multiplayer.getGlobalBounds().top + (m_multiplayer.getSize().y / 2));
}

void Menu::OnDestroy()
{

}

void Menu::Update(float _dt)
{

}

void Menu::Draw(sf::RenderWindow &_window)
{
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
