#pragma once
#include <raylib.h>
#include "gameManager.h"

typedef enum GameScreen {TITLE, GAMEPLAY /*Add more screens later*/} GameScreen;

class ScreenManager
{
    public:
        ScreenManager(int width, int height);
        ~ScreenManager();
        void init();
        void update();
        void draw();
    private:
        int width, height;
        GameScreen currentScreen;
        Texture2D background;
        Game game;
        float scale;
};