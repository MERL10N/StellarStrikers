#pragma once
#include "player.h"
#include "Enemy.h"
#include "enemySpawner.h"

class Powerup;

typedef enum GameScreen {TITLE, GAMEPLAY, PAUSED, GAMEOVER} GameScreen;

class Game{
    public:
        Game();
        ~Game();
        void draw();
        void update();
        void handleInput();
        bool gameOver(); //temporary for when the player dies change the code when post game screen is added
        void reset(); 
    private: 
        void DeleteInactiveBullets();
        Player player;
        Powerup* powerup;
        Powerup* rapidFirePowerup;

        std::vector<Enemy*> enemies;
        EnemySpawner* enemySpawner;
        int gamepad;
        float leftStickAxisX;
        float leftStickAxisY;
        float leftStickDeadzoneX;
        float leftStickDeadzoneY;
        GameScreen currentScreen;
};