#include "gameManager.h"
#include "powerup.h"
#include "healthPowerUp.h"

#include "rapidFirePowerup.h"
#include <iostream>

Game::Game()
: gamepad(0),
  leftStickAxisX(0.f),
  leftStickAxisY(0.f),
  leftStickDeadzoneX(0.1f),
  leftStickDeadzoneY(0.1f),
  powerup(new HealthPowerUp(Vector2{GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f}, 0.25f, ASSETS_PATH"healthpowerup.png")),
  rapidFirePowerup(new RapidFirePowerup(Vector2{GetScreenWidth() * 0.25f, GetScreenHeight() * 0.25f}, 0.25f, ASSETS_PATH"rapidfirepowerup.png"))
{
    enemies.push_back(new Enemy(GetScreenWidth(), GetScreenHeight()));
}

Game::~Game()
{
    if (powerup)
        delete powerup;

    if (rapidFirePowerup)
        delete rapidFirePowerup;

    for (auto enemy : enemies)
    {
        delete enemy;
    }
    enemies.clear();

}

void Game::update()
{
    float deltaTime = GetFrameTime();
    for(auto& bullet : player.bulletsVector)
    {
        bullet->Update(deltaTime);
    }
    DeleteInactiveBullets();

    // Check if powerup is not nullptr and it collides with player
    if (powerup && CheckCollisionRecs(player.getDestination(), powerup->getDestination()))
    {
        delete powerup;
        powerup = nullptr;

        // TODO: Recover health of the player back to full health

        /*
         *   example:
         *   player.setHealth(100);
         * */
    }

    if (rapidFirePowerup && CheckCollisionRecs(player.getDestination(), rapidFirePowerup->getDestination()))
    {
        if (rapidFirePowerup->getActive() == false)
        {
            rapidFirePowerup->activatePowerup(player);
        }
    }

    if (rapidFirePowerup && rapidFirePowerup->getActive())
    {
        rapidFirePowerup->updatePowerup(player, deltaTime);

        if (rapidFirePowerup->getActive() == false)
        {
            delete rapidFirePowerup;
            rapidFirePowerup = nullptr;
        }
    }

    for (auto& enemy : enemies) {
        enemy->Update(deltaTime, player.getPosition());
    }
}

void Game::draw()
{
    // Check if powerup is not nullptr
    if (powerup)
    {
        powerup->Draw();
    }

   if (rapidFirePowerup && !rapidFirePowerup->getActive())
    {
        rapidFirePowerup->Draw();
    }

    player.draw();
    for(auto& bullet : player.bulletsVector)
    {
        bullet->Render();
    }

    for (auto& enemy : enemies)
    {
        enemy->Render();
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

    if (IsKeyDown(KEY_LEFT_SHIFT))
    {
        player.fireRocket();
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
        if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_TRIGGER_2))
        {
            // Player will shoot
            player.fireBullet();
        }
        if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_TRIGGER_1))
            player.fireRocket();

    }
}

void Game::DeleteInactiveBullets()
{
    for (int i = 0; i < player.bulletsVector.size(); ++i)
    {
        Projectile* projectile = player.bulletsVector[i];

        if (!projectile->isActive()) {
            Rocket* rocket = dynamic_cast<Rocket*>(projectile);
            if (rocket && rocket->hasExploded && !rocket->explosionAnimation.IsActive()) {
                delete rocket;
                player.bulletsVector.erase(player.bulletsVector.begin() + i);
                --i;
            } else if (!rocket) {
                delete projectile;
                player.bulletsVector.erase(player.bulletsVector.begin() + i);
                --i;
            }
        }
    }
}