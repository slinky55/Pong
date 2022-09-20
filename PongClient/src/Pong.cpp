#include "Pong.h"

Pong::Pong() = default;
Pong::~Pong()
{
    /*disconnect();*/
}
void Pong::init()
{
    m_window.create( sf::VideoMode({800, 600}), "Pong" );
    m_window.setFramerateLimit(60);

    m_sceneManager = SceneManager::Instance();

    m_sceneManager->AddScene("menu", std::make_shared<Menu>());
    m_sceneManager->AddScene("multiplayer", std::make_shared<Multiplayer>());
    m_sceneManager->AddScene("singleplayer", std::make_shared<Singleplayer>());

    m_sceneManager->SetCurrentScene("menu");
}

void Pong::run()
{
    while (m_window.isOpen())
    {
        PollEvents();
        Update();
        Draw();
    }
}

void Pong::PollEvents()
{
    sf::Event e{};

    while(m_window.pollEvent(e))
    {
        if (e.type == sf::Event::Closed)
        {
            m_window.close();
        }
    }

    m_sceneManager->CurrentScene()->Input(m_window);
}

void Pong::Update()
{
    m_sceneManager->CurrentScene()->Update(m_clock.restart().asSeconds());
}

void Pong::Draw()
{
    m_window.clear();
    m_sceneManager->CurrentScene()->Draw(m_window);
    m_window.display();
}


