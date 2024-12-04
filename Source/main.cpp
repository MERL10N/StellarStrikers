#include "raylib.h"
#include "gameManager.h"
#include "screenManager.h"


int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "CS100 Final Project");
    InitAudioDevice();
    SetTargetFPS(60);
    
    ScreenManager screenManager(width, height);
    screenManager.init();

    while (!WindowShouldClose())
    {
        screenManager.update();
        screenManager.draw();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}