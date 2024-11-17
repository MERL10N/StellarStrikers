#include "gameManager.h"

Game::Game()
: gamepad(0),
  leftStickAxisX(0.f),
  leftStickAxisY(0.f),
  leftStickDeadzoneX(0.1f),
  leftStickDeadzoneY(0.1f)
{
}

Game::~Game()
{
}

void Game::update()
{
    for(auto& bullet : player.bulletsVector)
    {
        bullet.update(GetFrameTime());
    }
    DeleteInactiveBullets();
}

void Game::draw()
{
    player.draw();
    for(auto& bullet : player.bulletsVector)
    {
        bullet.draw();
    }
}

void Game::handleInput()
{
    if(IsKeyDown(KEY_W))
    {
        player.moveForward();
    }
    if(IsKeyDown(KEY_S))
    {
        player.moveBackward();
    }
    if(IsKeyDown(KEY_A))
    {
        player.moveLeft();
    }
    if(IsKeyDown(KEY_D))
    {
        player.moveRight();
    }
    if(IsKeyDown(KEY_SPACE))
    {
        player.fireBullet();
    }


    if (IsGamepadAvailable(0))
    {
       leftStickAxisX = GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_X);
       leftStickAxisY = GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_Y);

       if (leftStickAxisX > -leftStickDeadzoneX && leftStickAxisX < leftStickDeadzoneX) leftStickAxisX = 0.0f;
       if (leftStickAxisY > -leftStickDeadzoneY && leftStickAxisY < leftStickDeadzoneY) leftStickAxisY = 0.0f;

        // Get the input of the left thumbstick
        if (leftStickAxisX || leftStickAxisY)
        {
            player.moveWithController(leftStickAxisX, leftStickAxisY);
        }

        // Get the input of the right trigger (Xbox) or R2 Button (Playstation)
        if (IsGamepadButtonPressed(gamepad, GAMEPAD_BUTTON_RIGHT_TRIGGER_2))
        {
            // Player will shoot
        }

    }
}

void Game::DeleteInactiveBullets()
{
    for(int i = 0; i < player.bulletsVector.size(); ++i)
    {
        if(!player.bulletsVector[i].active)
        {
            player.bulletsVector.erase(player.bulletsVector.begin() + i);
            --i;
        }
    }
}