#include "raylib.h"
#include "gameManager.h"

typedef enum GameScreen {TITLE, GAMEPLAY /*Add more screens later*/} GameScreen;

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "CS100 Final Project");
    SetTargetFPS(60);

    Texture2D background = LoadTexture(ASSETS_PATH "background.png");
    Game game;

    GameScreen currentScreen = TITLE;

    // Scaling factor for background image
    float scaleX = (float)width/background.width;
    float scaleY = (float)height/background.height;
    float scale =  scaleX > scaleY ? scaleX : scaleY; // Scale the image to the window size


    while (!WindowShouldClose())
    {
        switch(currentScreen)
        {
            case TITLE:
            {
                //Update with different methods of entering gameplay screen
                if (IsKeyPressed(KEY_ENTER))
                    currentScreen = GAMEPLAY;
            } break;
            case GAMEPLAY:
            {

            } break;
            default: break;
        }
        
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch(currentScreen)
        {
            case TITLE:
            {
                DrawTextureEx(background, Vector2{0, 0}, 0.0, scale, WHITE);
                DrawText("PRESS ENTER TO START GAME", 360, 360, 30, WHITE);
                DrawText("STELLAR STRIKERS", 300, 160, 60, WHITE);
            } break;
            case GAMEPLAY:
            {
                game.handleInput();
                game.update();

                DrawTextureEx(background, Vector2{0, 0}, 0.0, scale, WHITE);
                game.draw();
            } break;
            default: break;
        }

        EndDrawing();
    }

    // Free textures from GPU memory
    UnloadTexture(background);

    CloseWindow();

    return 0;
}