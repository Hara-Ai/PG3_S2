#include "Game.h"
#include "TitleScene.h"
#include "player.h"
Game* Game::instance = nullptr;

Game::Game() {
    currentScene = new TitleScene();
}

Game::~Game() {
    delete currentScene;
}

Game* Game::GetInstance() {
    if (instance == nullptr) {
        instance = new Game();
    }
    return instance;
}

void Game::ChangeScene(Scene* newScene) {
    delete currentScene;
    currentScene = newScene;
}

void Game::Initialize()
{
    currentScene->Initialize();
}

void Game::Update() {
    currentScene->Update();
}

void Game::Draw() {
    currentScene->Draw();
}

void Game::Exit() {
    delete instance;
    instance = nullptr;
}
