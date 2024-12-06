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

    pauseButton = { (float)(width - 130), 20.0f, 90.0f, 40.0f }; 
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

            // Check for pause button click
            if (CheckCollisionPointRec(GetMousePosition(), pauseButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                currentScreen = PAUSED;

            if(game.gameOver()) {
                currentScreen = GAMEOVER; 
            }

            break;

        case PAUSED:
            {
                bool goToHome = false; 
                bool isPaused = false; 
                bool resume = false; 

                pauseMenu.handleInput(resume, goToHome);
                if (!isPaused && !goToHome) {
                   isPaused = true; 
                }
                
                if (resume) {
                    currentScreen = GAMEPLAY;
                    resume = false; 
                }

                if (goToHome) {
                    goToHome = false;
                    game.reset(); 
                    currentScreen = TITLE;
                }
            } break;

        case GAMEOVER:
        {
            Rectangle returnHomeButton = { (float)(width / 2 - 100), (float)(height / 2 + 50), 200, 50 };

            if (CheckCollisionPointRec(GetMousePosition(), returnHomeButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                game.reset(); // Reset game state
                currentScreen = TITLE; // Go back to the title screen
            }
        } break;

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
            
            // Draw the pause button
            DrawRectangleRec(pauseButton, LIGHTGRAY);
            DrawText("Pause", pauseButton.x + 10, pauseButton.y + 10, 20, BLACK);
            break;
        case PAUSED:
            pauseMenu.draw(); // Draw the pause menu
            break;
        case GAMEOVER:
        {
            DrawTextureEx(background, Vector2{0, 0}, 0.0, scale, WHITE);

            DrawText("GAME OVER!", width / 2 - MeasureText("GAME OVER!", 60) / 2, height / 2 - 100, 60, RED);

            Rectangle returnHomeButton = { (float)(width / 2 - 100), (float)(height / 2 + 50), 200, 50 };
            DrawRectangleRec(returnHomeButton, WHITE);
            DrawText("RETURN HOME", (int)(returnHomeButton.x + 20), (int)(returnHomeButton.y + 15), 20, BLACK);
        }
break;



        default:
            break;
    }

    EndDrawing();
}