#pragma once
#include "player.h"
#include "Enemy.h"

class Powerup;

typedef enum GameScreen {TITLE, GAMEPLAY} GameScreen;

class Game{
    public:
        Game();
        ~Game();
        void draw();
        void update();
        void handleInput();
        void gameOver(); //temporary for when the player dies change the code when post game screen is added

    private: 
        void DeleteInactiveBullets();
        Player player;
        Powerup* powerup;
        Powerup* rapidFirePowerup;

        std::vector<Enemy*> enemies;
        
        int gamepad;
        float leftStickAxisX;
        float leftStickAxisY;
        float leftStickDeadzoneX;
        float leftStickDeadzoneY;
        GameScreen currentScreen;
};