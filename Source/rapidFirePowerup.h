#ifndef RAPIDFIREPOWERUP_H
#define RAPIDFIREPOWERUP_H
#include "powerup.h"

class RapidFirePowerup : public Powerup
{
  public:
    RapidFirePowerup(); // Default Constructor
    RapidFirePowerup(const Vector2& position, const float &scale, const char* assetPath); // Overloaded constructor
    virtual ~RapidFirePowerup();
    void Draw() override;
    Vector2 getPosition() override;
    Rectangle getDestination() override;

  private:
    Vector2 position;
    Texture2D texture;
    Rectangle sourceRect;
    Rectangle destinationRect;
    float scale;
};

#endif //RAPIDFIREPOWERUP_H