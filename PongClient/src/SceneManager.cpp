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