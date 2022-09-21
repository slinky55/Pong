
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

#include "Pong.h"

Pong::Pong() = default;
Pong::~Pong()
{
    m_sceneManager->CurrentScene()->OnDestroy();
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


