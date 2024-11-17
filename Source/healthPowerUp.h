//
// Created by Kian Marvi on 11/16/24.
//

#ifndef HEALTHPOWERUP_H
#define HEALTHPOWERUP_H
#include "powerup.h"
#include <raylib.h>

class HealthPowerUp : public Powerup
{
  public:
    HealthPowerUp(); // Default Constructor
    HealthPowerUp(const Vector2& position, const int &healthBoost); // Overloaded constructo
    ~HealthPowerUp();
    void Spawn() override;
    void DeSpawn() override;
    Vector2 getPosition();

  private:
    Vector2 position;
    int healthBoost;
};



#endif //HEALTHPOWERUP_H
