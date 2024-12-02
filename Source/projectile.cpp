//
// Created by Kian Marvi on 11/29/24.
//

#include "projectile.h"
#include <cmath>

Projectile::Projectile(const Vector2& position, float rotation, float speed, float lifespan, const char* texturePath)
    :position(position),
     speed(speed),
     rotation(rotation),
     lifespan(lifespan),
     texture(LoadTexture(texturePath)),
     creationTime(GetTime()),
     active(true)
{
}

bool Projectile::Update(float deltaTime)
{
    if(!active || (GetTime() > creationTime + lifespan))
    {
        active = false;
        UnloadTexture(texture);
        return false;
    }

    position.x += speed * deltaTime * sin(rotation * DEG2RAD);
    position.y -= speed * deltaTime * cos(rotation * DEG2RAD);

    return true;
}

void Projectile::Render() const
{
    if(active)
    {
        DrawTextureEx(texture, position, rotation - 90, 0.02, WHITE);
    }
}