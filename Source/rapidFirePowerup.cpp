#include "rapidFirePowerup.h"
#include "player.h"
#include <iostream>

RapidFirePowerup::RapidFirePowerup(const Vector2& position, const float &scale, const char* assetPath)
    : position(Vector2{position.x, position.y}),
      texture(LoadTexture(assetPath)),
      scale(scale),
      powerupTimer(0.0f),
      isActive(false),
      powerUpSFX(LoadSound(ASSETS_PATH "powerUpSFX.mp3"))
{
}

RapidFirePowerup::~RapidFirePowerup()
{
  if (texture.id > 0)
  {
    UnloadTexture(texture);
    UnloadSound(powerUpSFX);
  }
}

void RapidFirePowerup::activatePowerup(Player &player)
{
  PlaySound(powerUpSFX);
  isActive = true;
   player.setFireRate(2.0f);
   powerupTimer = 10.f;
}

void RapidFirePowerup::deactivatePowerup(Player &player)
{
  isActive = false;
  player.setFireRate(1.0f);
  powerupTimer = 0;
}

void RapidFirePowerup::updatePowerup(Player &player, float &deltaTime)
{
  if (!isActive)
      return;
      
    powerupTimer -= deltaTime;
    std::cout << "Timer: " << powerupTimer << std::endl;
    if (powerupTimer <= 0.0f)
    {
        powerupTimer = 0.0f;
        deactivatePowerup(player);
    }
}

void RapidFirePowerup::Draw()
{
    sourceRect = {0,0, (float)texture.width, (float)texture.height};
    destinationRect = {position.x - (texture.width * scale), position.y - (texture.height * scale), texture.width * scale, texture.height * scale};
    // Draw the rapidfire powerup sprite
    DrawTexturePro(texture, sourceRect, destinationRect, Vector2{0.f,0.f}, 0.f, WHITE);
}

bool RapidFirePowerup::getActive()
{
   return isActive;
}

Rectangle RapidFirePowerup::getDestination()
{
    return destinationRect;
}

Vector2 RapidFirePowerup::getPosition()
{
    return position;
}