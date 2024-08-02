#include "InputManager.h"
#include "Novice.h"
#include <cstring>

InputManager* InputManager::instance = nullptr;

InputManager::InputManager() {
    std::memset(keys, 0, 256);
    std::memset(preKeys, 0, 256);
}

InputManager::~InputManager() {}

InputManager* InputManager::GetInstance() {
    if (instance == nullptr) {
        instance = new InputManager();
    }
    return instance;
}

void InputManager::Update() {
    std::memcpy(preKeys, keys, 256);
    Novice::GetHitKeyStateAll(keys);
}

bool InputManager::IsKeyPressed(int key) {
    return (keys[key]);
}