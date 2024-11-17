//
// Created by Kian Marvi on 11/16/24.
//

#include "healthPowerUp.h"

HealthPowerUp::HealthPowerUp()
    : position(Vector2{0.0f, 0.0f}),
      healthBoost(0.0f)
{
}

HealthPowerUp::HealthPowerUp(const Vector2 &position, const int &healthBoost)
    : position(position),
      healthBoost(healthBoost)
{
}

HealthPowerUp::~HealthPowerUp()
{
}

void HealthPowerUp::Spawn()
{
}

void HealthPowerUp::DeSpawn()
{
}

Vector2 HealthPowerUp::getPosition()
{
}





