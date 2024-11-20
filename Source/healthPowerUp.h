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
    HealthPowerUp(const Vector2& position, const float &scale, const char* assetPath); // Overloaded constructor
    virtual ~HealthPowerUp();
    void Draw() override;
    Vector2 getPosition() override;
    Rectangle getDestination() override;

  private:
    Vector2 position;
    Texture2D texture;
    Rectangle sourceRect;
    Rectangle destinationRect;
    int healthBoost;
    float scale;
};



#endif //HEALTHPOWERUP_H
