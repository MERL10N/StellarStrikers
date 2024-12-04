#pragma once
#include "powerup.h"

class Player;

class RapidFirePowerup : public Powerup
{
  public:
    RapidFirePowerup(); // Default Constructor
    RapidFirePowerup(const Vector2& position, const float &scale, const char* assetPath); // Overloaded constructor
    ~RapidFirePowerup() override;
    void activatePowerup(Player &player) override;
    void deactivatePowerup(Player &player) override;
    void updatePowerup(Player &player, float &deltaTime) override;
    bool getActive() override;
    void Draw() override;

    Vector2 getPosition() override;
    Rectangle getDestination() override;

  private:
    Vector2 position;
    Texture2D texture;
    Rectangle sourceRect;
    Rectangle destinationRect;
    float scale;
    bool isActive;
    float powerupTimer;
    Sound powerUpSFX;
};

