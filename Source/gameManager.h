#pragma once
#include "player.h"
#include "Enemy.h"
#include "score.h"
#include <vector>
#include "Leaderboard.h"

class Powerup;

typedef enum GameScreen {TITLE, GAMEPLAY, PAUSED, GAMEOVER, SCOREBOARD} GameScreen;

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
        Leaderboard board;

        // std::vector<Enemy*> enemies;
        std::vector<std::unique_ptr<Enemy>> enemies;

        Score curScore;
        
        int gamepad;
        float leftStickAxisX;
        float leftStickAxisY;
        float leftStickDeadzoneX;
        float leftStickDeadzoneY;
        GameScreen currentScreen;
};