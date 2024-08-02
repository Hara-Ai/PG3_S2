#pragma once

class InputManager {
public:
    static InputManager* GetInstance();
    void Update();
    bool IsKeyPressed(int key);

private:
    InputManager();
    ~InputManager();
    char keys[256];
    char preKeys[256];
    static InputManager* instance;
};