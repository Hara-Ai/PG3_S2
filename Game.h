#pragma once
#include "Scene.h"

class Game {
public:
    static Game* GetInstance();
    void ChangeScene(Scene* newScene);
    void Initialize();
    void Update();
    void Draw();
    void Exit();

private:
    Game();
    ~Game();
    Scene* currentScene;
    static Game* instance;
};