#include "bullet.h"

Bullet::Bullet(const Vector2 &position, float rotation)
    :Projectile(position, rotation, 500.0f, 3.0f, ASSETS_PATH "playerbullet.png")
{
}

bool Bullet::Update(float deltaTime)
{
    return Projectile::Update(deltaTime);
}