#include <Pong.h>

SceneManager* gSceneManager = SceneManager::Instance();

int main(int argc, char** argv)
{
    Pong p;

    p.init();
    p.run();

    delete gSceneManager;

    return 0;
}
