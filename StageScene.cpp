#include "StageScene.h"
#include "Novice.h"
#include "InputManager.h"
#include "Game.h"
#include "ClearScene.h"
#include "player.h"
#include "enemy.h"

StageScene::StageScene() : enemyCount(5) // コンストラクタ定義
{
    player = new Player();
    player->pos.x = 1280 / 2;
    player->pos.y = 720 / 2;
    player->radius = 50;
    player->speed.x = 10;
    player->speed.y = 10;

    enemy = new Enemy();
    enemy->pos.x = 1280 / 2;
    enemy->pos.y = 150;
    enemy->radius = 50;
    enemy->speed.x = 5;
    enemy->speed.y = 5;

    bullet = new Bullet();
    bullet->pos.x = 0;
    bullet->pos.y = 0;
    bullet->radius = 10;
    bullet->speed.x = 10;
    bullet->speed.y = 10;
} 

void StageScene::Initialize()
{
   
}

void StageScene::Update() {
    if (enemyCount == 0) {
        Game::GetInstance()->ChangeScene(new ClearScene());
    }

    // シンプルな敵のロジック
    //if (InputManager::GetInstance()->IsKeyPressed(DIK_SPACE))
    //{
    //    enemyCount--;
    //}

    ////
    // プレイヤーの移動処理
    ////

    if (InputManager::GetInstance()->IsKeyPressed(DIK_D))
    {
        player->pos.x += player->speed.x;
    }

    if (InputManager::GetInstance()->IsKeyPressed(DIK_A))
    {
        player->pos.x -= player->speed.x;
    }

    if (InputManager::GetInstance()->IsKeyPressed(DIK_S))
    {
        player->pos.y += player->speed.y;
    }

    if (InputManager::GetInstance()->IsKeyPressed(DIK_W))
    {
        player->pos.y -= player->speed.y;
    }

    ////
   // 敵の移動処理
   ////

    if (fastSpeed == false)
    {
        enemy->pos.x += enemy->speed.x;
    }

    if (fastSpeed == true)
    {
        enemy->pos.x -= enemy->speed.x;
    }

    if (enemy->pos.x - enemy->radius <= 0 && enemy->pos.x + enemy->radius <= 1280)
    {
        fastSpeed = false;
    }

    if (enemy->pos.x + enemy->radius >= 0 && enemy->pos.x + enemy->radius >= 1280)
    {
        fastSpeed = true;
    }

    ////
    // 弾の更新処理
    ////

    if (InputManager::GetInstance()->IsKeyPressed(DIK_SPACE) && isBullet == false)
    {
        bullet->pos.y = player->pos.y;
        bullet->pos.x = player->pos.x;
        isBullet = true;
    }

    if (isBullet == true)
    {
        bullet->pos.y -= bullet->speed.y;
    }

    if (player->pos.y + bullet->pos.y < 0)
    {
        isBullet = false;
        bullet->pos.y = -999;
    }

    //２点間の距離（の２乗）を求める//
    distance = (bullet->pos.y - enemy->pos.y) * (bullet->pos.y - enemy->pos.y)//高さの２乗
        + (bullet->pos.x - enemy->pos.x) * (bullet->pos.x - enemy->pos.x);//幅の２乗

    //当たっているかどうか//
    if (distance <= (bullet->radius + enemy->radius) * (bullet->radius + enemy->radius))
    {
        Game::GetInstance()->ChangeScene(new ClearScene());
    }
}

void StageScene::Draw()
{
    // 弾
    Novice::DrawEllipse((int)bullet->pos.x,(int)bullet->pos.y, (int)bullet->radius, (int)bullet->radius, 0.0f, BLACK, kFillModeSolid);
    // プレイヤー
    Novice::DrawEllipse((int)player->pos.x, (int)player->pos.y, (int)player->radius, (int)player->radius, 0.0f, WHITE, kFillModeSolid);
    // 敵
    Novice::DrawEllipse((int)enemy->pos.x, (int)enemy->pos.y, (int)enemy->radius, (int)enemy->radius, 0.0f, RED, kFillModeSolid);
    
}
