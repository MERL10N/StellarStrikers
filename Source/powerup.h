//
// Created by Kian Marvi on 11/16/24.
//

#ifndef POWERUP_H
#define POWERUP_H

class Powerup
{
  public:
    virtual void Spawn() = 0;
    virtual void DeSpawn() = 0;
};

#endif //POWERUP_H
