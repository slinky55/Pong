#pragma once

#include <Multiplayer.h>
#include <Menu.h>

#include <SceneManager.h>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

class Pong {
public:
    Pong();
    ~Pong();

    void init();
    void run();
private:

    sf::RenderWindow m_window;
    sf::Clock m_clock;

    SceneManager* m_sceneManager;
    Menu m_menuScene;

    void PollEvents();
    void Update();
    void Draw();

};
