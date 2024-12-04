//
// Created by Kian Marvi on 11/29/24.
//

#pragma once

#include "projectile.h"
#include "spriteAnimation.h"


class Rocket : public Projectile
{
public:
    Rocket(const Vector2 &position, float rotation);
    ~Rocket();
    bool Update(float deltaTime) override;
    void Render() const override;
    bool hasExploded;
    SpriteAnimation explosionAnimation;
private:
    Vector2 explosionPosition;
};


