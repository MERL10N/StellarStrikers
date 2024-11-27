//
// Created by Kian Marvi on 11/16/24.
//

#ifndef HEALTHPOWERUP_H
#define HEALTHPOWERUP_H
#include "powerup.h"

class HealthPowerUp : public Powerup
{
  public:
    HealthPowerUp(); // Default Constructor
    HealthPowerUp(const Vector2& position, const float &scale, const char* assetPath); // Overloaded constructor
    virtual ~HealthPowerUp();
    void Draw() override;
    Vector2 getPosition() override;
    Rectangle getDestination() override;
    void activatePowerup(Player &player) override {};
    void deactivatePowerup(Player &player) override {};
    void updatePowerup(Player &player, float &deltaTime) override{};
    bool getActive() override {};

  private:
    Vector2 position;
    Texture2D texture;
    Rectangle sourceRect;
    Rectangle destinationRect;
    float scale;
    Sound powerUpSFX;
};

#endif //HEALTHPOWERUP_H
