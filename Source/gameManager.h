#pragma once
#include "player.h"

class Game{
    public:
        Game();
        ~Game();
        void draw();
        void update();
        void handleInput();
    private: 
        void DeleteInactiveBullets();
        Player player;
        int gamepad;
        float leftStickAxisX;
        float leftStickAxisY;
        float leftStickDeadzoneX;
        float leftStickDeadzoneY;
};