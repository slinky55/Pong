#pragma once

#include <unordered_map>
#include <memory>

#include <Scene.h>

class SceneManager
{
public:
    static SceneManager* Instance();

    void AddScene(const std::string& _id, std::shared_ptr<Scene_B> _scene);
    void SetCurrentScene(const std::string& _id);

    std::shared_ptr<Scene_B> Get(const std::string& _id);
    std::shared_ptr<Scene_B> CurrentScene();
private:
    std::unordered_map<std::string, std::shared_ptr<Scene_B>> m_scenes;
    std::shared_ptr<Scene_B> m_current;

    static SceneManager* m_instance;

    // Prevent construction and copying
    SceneManager() = default;
};
