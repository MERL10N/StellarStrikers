//
// Created by Kian Marvi on 11/16/24.
//

#ifndef POWERUP_H
#define POWERUP_H

#include <raylib.h>
class Powerup
{
  public:
    virtual void Draw() = 0;
    virtual ~Powerup() = default;
    virtual Rectangle getDestination() = 0;
};

#endif //POWERUP_H
