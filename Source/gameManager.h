#pragma once
#include "player.h"

class Powerup;
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
        Powerup* powerup;
        Powerup* rapidFirePowerup;
        
        int gamepad;
        float leftStickAxisX;
        float leftStickAxisY;
        float leftStickDeadzoneX;
        float leftStickDeadzoneY;
};