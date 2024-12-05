//
// Created by Kian Marvi on 11/16/24.
//

#include "healthPowerUp.h"

HealthPowerUp::HealthPowerUp()
    : scale(0.25f),
      powerUpSFX(LoadSound(ASSETS_PATH "powerUpSFX.mp3"))
{
  position = Vector2{(static_cast<float>(GetScreenWidth()) - static_cast<float>(texture.width)) * 0.25f, (static_cast<float>(GetScreenHeight()) - static_cast<float>(texture.height))* 0.25f};
  texture = LoadTexture(ASSETS_PATH"healthpowerup.png");
}

HealthPowerUp::HealthPowerUp(const Vector2 &position, const float &scale, const char* assetPath)
    : position(Vector2{position.x, position.y}),
      texture(LoadTexture(assetPath)),
      scale(scale),
      powerUpSFX(LoadSound(ASSETS_PATH "powerUpSFX.mp3"))
{
}

HealthPowerUp::~HealthPowerUp()
{
  if (texture.id > 0)
  {
    UnloadTexture(texture);
    UnloadSound(powerUpSFX);
  }
}

void HealthPowerUp::Draw()
{
  sourceRect = {0,0, static_cast<float>(texture.width), static_cast<float>(texture.height)};
  destinationRect = {position.x - (texture.width * scale), position.y - (texture.height * scale), texture.width * scale, texture.height * scale};
  // Draw the health powerup sprite
   DrawTexturePro(texture, sourceRect, destinationRect, Vector2{0.f,0.f}, 0.f, WHITE);
}

Vector2 HealthPowerUp::getPosition()
{
   return position;
}

Rectangle HealthPowerUp::getDestination()
{
  return destinationRect;
}






