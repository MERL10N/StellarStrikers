#include "raylib.h"

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "CS100 Final Project");
    SetTargetFPS(60);

    Texture2D texture = LoadTexture(ASSETS_PATH "player.png"); 
    Texture2D background = LoadTexture(ASSETS_PATH "background.png");

    // Scaling factor for background image
    float scaleX = (float)width/background.width;
    float scaleY = (float)height/background.height;
    float scale =  scaleX > scaleY ? scaleX : scaleY; // Scale the image to the window size


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);


        Vector2 Position {100.f, 250.f};

        DrawTextureEx(background, Vector2{0, 0}, 0.0, scale, WHITE);
        DrawTextureEx(texture, Position, 0.0f, 0.05, WHITE);


        EndDrawing();
    }

    // Free textures from GPU memory
    UnloadTexture(texture);
    UnloadTexture(background);

    CloseWindow();

    return 0;
}