#pragma once
#include "Scene.h"
#include "Novice.h"

// 前方宣言
class StageScene;

class TitleScene : public Scene {
public:
    void Initialize() override;
    void Update() override;
    void Draw() override;
private:
    //タイトルの画像
    int TitleImage = Novice::LoadTexture("./resources/TitleImage.png");
};
