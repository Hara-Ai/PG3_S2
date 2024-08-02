#include "ClearScene.h"
#include "Novice.h"
#include "InputManager.h"
#include "Game.h"

void ClearScene::Initialize()
{
}

void ClearScene::Update() {
    if (InputManager::GetInstance()->IsKeyPressed(DIK_ESCAPE)) {
        Game::GetInstance()->Exit();
    }
}

void ClearScene::Draw() 
{
    Novice::DrawBox(0, 0, 1280, 720, 0.0f, WHITE, kFillModeSolid);
}
