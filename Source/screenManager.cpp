#include "screenManager.h"

ScreenManager::ScreenManager(int width, int height)
: width(width), 
  height(height), 
  currentScreen(TITLE)
{
}

ScreenManager::~ScreenManager()
{
    UnloadTexture(background);
}

void ScreenManager::init()
{
    background = LoadTexture(ASSETS_PATH "background.png");

    // Scaling factor for background image
    float scaleX = (float)width/background.width;
    float scaleY = (float)height/background.height;
    scale =  scaleX > scaleY ? scaleX : scaleY; // Scale the image to the window size
}

void ScreenManager::update()
{
    switch (currentScreen) {
        case TITLE:
            {
            //if (IsKeyPressed(KEY_ENTER))
            //   currentScreen = GAMEPLAY;
            
            Rectangle startButton = { (float)(width / 2 - 100), (float)(height / 2 + 50), 200, 50 };

            if (CheckCollisionPointRec(GetMousePosition(), startButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                currentScreen = GAMEPLAY;
            
            if (IsGamepadAvailable(0))
            {
                if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_MIDDLE_RIGHT))
                    currentScreen = GAMEPLAY;
            }
            } break;
        case GAMEPLAY:
            game.handleInput();
            game.update();
            break;
        default:
            break;
    }
}

void ScreenManager::draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    switch (currentScreen)
    {
        case TITLE:
            {
            DrawTextureEx(background, Vector2{0, 0}, 0.0, scale, WHITE);
            //DrawText("PRESS ENTER TO START GAME", 360, 360, 30, WHITE);
            DrawText("STELLAR STRIKERS", 300, 160, 60, WHITE);

            Rectangle startButton = { (float)(width / 2 - 100), (float)(height / 2 + 50), 200, 50 };
            DrawRectangleRec(startButton, WHITE);
            DrawText("START GAME", (int)(startButton.x + 30), (int)(startButton.y + 15), 20, BLACK);  
            } break;
        case GAMEPLAY:
            DrawTextureEx(background, Vector2{0, 0}, 0.0, scale, WHITE);
            game.draw();
            break;
        default:
            break;
    }

    EndDrawing();
}