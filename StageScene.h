#pragma once
#include "Scene.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"

class StageScene : public Scene {
public:
    StageScene(); // コンストラクタ宣言
    void Initialize() override;
    void Update() override;
    void Draw() override;

private:
    int enemyCount;
    float distance;
    bool fastSpeed = false;
    bool isBullet = false;
    Player* player;
    Enemy* enemy;
    Bullet* bullet;
};
