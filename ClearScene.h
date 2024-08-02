#pragma once
#include "Scene.h"
#include "Novice.h"

class ClearScene : public Scene {
public:
    void Initialize() override;
    void Update() override;
    void Draw() override;
private:
    //クリアの画像
    int clearImage = Novice::LoadTexture("./resources/clearImage.png");
};
