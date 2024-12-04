//
// Created by Kian Marvi on 11/16/24.
//

#pragma once

#include <raylib.h>
#include "player.h"
class Powerup
{
  public:
    virtual void Draw() = 0;
    virtual ~Powerup() = default;
    virtual void activatePowerup(Player &player) = 0;
    virtual void deactivatePowerup(Player &player) = 0;
    virtual void updatePowerup(Player &player, float &deltaTime) = 0;
    virtual bool getActive() = 0;
    virtual Rectangle getDestination() = 0;
    virtual Vector2 getPosition() = 0;
};


