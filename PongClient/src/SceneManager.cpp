
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

#include <SceneManager.h>

SceneManager* SceneManager::m_instance = nullptr;

SceneManager* SceneManager::Instance()
{
    if (m_instance == nullptr)
        m_instance = new SceneManager();
    return m_instance;
}

void SceneManager::AddScene(const std::string& _id, std::shared_ptr<Scene_B> _scene)
{
    m_scenes[_id] = _scene;
}

void SceneManager::SetCurrentScene(const std::string& _id)
{
    if (m_current != nullptr)
        m_current->OnDestroy();
    m_current = m_scenes.at(_id);
    m_current->OnAwake();
}

std::shared_ptr<Scene_B> SceneManager::Get(const std::string &_id)
{
    return m_scenes.at(_id);
}

std::shared_ptr<Scene_B> SceneManager::CurrentScene()
{
    return m_current;
}