#include "rapidFirePowerup.h"


RapidFirePowerup::RapidFirePowerup()
   : position(Vector2{((float)GetScreenWidth() - (float)texture.width) * 0.25f, ((float)GetScreenHeight() - (float)texture.height)* 0.25f}),
      texture(LoadTexture(ASSETS_PATH"rapidfirepowerup.png")),
      scale(0.25f)
{
}

RapidFirePowerup::RapidFirePowerup(const Vector2& position, const float &scale, const char* assetPath)
    : position(Vector2{position.x, position.y}),
      texture(LoadTexture(assetPath)),
      scale(scale)
{
}

RapidFirePowerup::~RapidFirePowerup()
{
  if (texture.id > 0)
  {
    UnloadTexture(texture);
  }
}

void RapidFirePowerup::Draw()
{
    sourceRect = {0,0, (float)texture.width, (float)texture.height};
    destinationRect = {position.x - (texture.width * scale), position.y - (texture.height * scale), texture.width * scale, texture.height * scale};
    // Draw the rapidfire powerup sprite
    DrawTexturePro(texture, sourceRect, destinationRect, Vector2{0.f,0.f}, 0.f, WHITE);
}

Rectangle RapidFirePowerup::getDestination()
{
    return destinationRect;
}

Vector2 RapidFirePowerup::getPosition()
{
    return position;
}