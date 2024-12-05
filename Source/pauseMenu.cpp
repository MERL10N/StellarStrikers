#include "pauseMenu.h"
#include "string"

PauseMenu::PauseMenu() {
    resumeButton = { 540.0f, 300.0f, 200.0f, 50.0f }; // x, y, width, height
    homeButton = { 540.0f, 400.0f, 200.0f, 50.0f };
}

void PauseMenu::handleInput(bool &resume, bool &goToHome) {
    // Get the current mouse position
    Vector2 mousePos = GetMousePosition();

    // Check if the left mouse button is pressed
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (CheckCollisionPointRec(mousePos, resumeButton)) {
            resume = true;
        }
        if (CheckCollisionPointRec(mousePos, homeButton)) {
            goToHome = true;
        }
    }
}

void PauseMenu::draw() {
    // Draw background
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.7f));

    // Draw Paused on Screen
    DrawText("PAUSED", 550, 200, 40, WHITE);

    // Draw resume button
    DrawRectangleRec(resumeButton, LIGHTGRAY);
    DrawText("Resume", resumeButton.x + 50, resumeButton.y + 15, 20, BLACK);

    // Draw home button
    DrawRectangleRec(homeButton, LIGHTGRAY);
    DrawText("Home", homeButton.x + 75, homeButton.y + 15, 20, BLACK);
}