#include "TitleScene.h"
#include "StageScene.h" 
#include "Novice.h"
#include "InputManager.h"
#include "Game.h"



void TitleScene::Initialize()
{

}

void TitleScene::Update()
{
    if (InputManager::GetInstance()->IsKeyPressed(DIK_RETURN))
    {
        Game::GetInstance()->ChangeScene(new StageScene());
    }
}

void TitleScene::Draw()
{
    Novice::DrawBox(0, 0, 1280, 720, 0.0f, WHITE, kFillModeSolid);
    Novice::DrawSprite(0, 0, TitleImage, 1.0f, 1.0f, 0.0f, BLUE);

}
