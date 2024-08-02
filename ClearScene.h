#pragma once
#include "Scene.h"

class ClearScene : public Scene {
public:
    void Initialize() override;
    void Update() override;
    void Draw() override;
};
