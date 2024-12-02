#pragma once
#include "projectile.h"

class Bullet : public Projectile
{
public:
    Bullet(const Vector2 &position, float rotation);
    bool Update(float deltaTime) override;
};
