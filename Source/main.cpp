#include "raylib.h"
#include "gameManager.h"

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "CS100 Final Project");
    SetTargetFPS(60);

    Texture2D background = LoadTexture(ASSETS_PATH "background.png");
    Game game;

    // Scaling factor for background image
    float scaleX = (float)width/background.width;
    float scaleY = (float)height/background.height;
    float scale =  scaleX > scaleY ? scaleX : scaleY; // Scale the image to the window size


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        game.handleInput();

        DrawTextureEx(background, Vector2{0, 0}, 0.0, scale, WHITE);
        game.draw();

        EndDrawing();
    }

    // Free textures from GPU memory
    UnloadTexture(background);

    CloseWindow();

    return 0;
}