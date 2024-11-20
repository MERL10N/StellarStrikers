//
// Created by Kian Marvi on 11/16/24.
//

#include "healthPowerUp.h"

HealthPowerUp::HealthPowerUp()
    : position(Vector2{((float)GetScreenWidth() - (float)texture.width) * 0.25f, ((float)GetScreenHeight() - (float)texture.height)* 0.25f}),
      healthBoost(20.0f),
      texture(LoadTexture(ASSETS_PATH"healthpowerup.png")),
      scale(0.25f)
{
}

HealthPowerUp::HealthPowerUp(const Vector2 &position, const int &healthBoost)
    : position(Vector2{position.x, position.y}),
      healthBoost(healthBoost),
      texture(LoadTexture(ASSETS_PATH"healthpowerup.png")),
      scale(0.25f)
{
}

HealthPowerUp::~HealthPowerUp()
{
    UnloadTexture(texture);
}

void HealthPowerUp::Draw()
{
  sourceRect = {0,0, (float)texture.width, (float)texture.height};
  destinationRect = {position.x - (texture.width * scale), position.y - (texture.height * scale), texture.width * scale, texture.height * scale};
  // Draw the health powerup sprite
   DrawTexturePro(texture, sourceRect, destinationRect, Vector2{0.f,0.f}, 0.f, WHITE);
}

Vector2 HealthPowerUp::getPosition()
{
   return position;
}

Rectangle HealthPowerUp::getRect()
{
  return destinationRect;
}

int HealthPowerUp::getHealthBoost()
{
   return healthBoost;
}





