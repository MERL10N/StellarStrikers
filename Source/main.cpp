#include "raylib.h"

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "CS100 Final Project");
    SetTargetFPS(60);

    Texture2D texture = LoadTexture(ASSETS_PATH"test.png"); 

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        const int texture_x = width * 0.5f - texture.width * 0.5f;
        const int texture_y = height * 0.5f - texture.height * 0.5f;
        DrawTexture(texture, texture_x, texture_y, WHITE);

        const char* text = "CS 100 Final Project";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, width * 0.5f - text_size.x * 0.5f, texture_y + texture.height + text_size.y + 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}