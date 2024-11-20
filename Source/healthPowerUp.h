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
    void Draw() override;
    int getHealthBoost();
    Vector2 getPosition();

    Rectangle getRect();

  private:
    Vector2 position;
    Texture2D texture;
    Rectangle sourceRect;
    Rectangle destinationRect;
    int healthBoost;
    float scale;
};



#endif //HEALTHPOWERUP_H
