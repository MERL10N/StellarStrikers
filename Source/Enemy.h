#pragma once
#include <raylib.h>

#include "projectile.h"
#include "bullet.h"
#include <vector>
#include <memory>
#include "health.h"

class Enemy
{
public:
  enum class State
   {
        CHASE,
        SHOOT,
        STOP,
        DIE
    };
    Enemy();
    Enemy(float screenWidth, float screenHeight);
    ~Enemy();

    void Update(float &deltaTime, const Vector2& position);
    void Render() const;

    inline bool IsAlive() const { return alive; }
    inline Health& getHealthComponent() { return health; }
    inline void setState(State newState) { currentState = newState; }
    Rectangle getHitBox() const; 
    std::vector<Projectile*> getBullets() const;


    private:
      bool alive;
      Vector2 position;
      Vector2 velocity;
      float speed;
      State currentState;
      Health health;

      std::vector<std::unique_ptr<Projectile>> bulletsVector;

      Texture2D texture;
      Vector2 origin;

      float screenWidth;
      float screenHeight;

      float shootTimer;
      float shootCooldown;
      float dieTimer;
      float shootingRange;

      float rotation;

      void Spawn(float &screenWidth, float &screenHeight);
      void UpdateChase(const Vector2& playerPosition, float deltaTime);
      void UpdateShoot(const Vector2 &playerPosition, float &deltaTime);
      void UpdateDie(float &deltaTime);
      void CleanUpBullets();
};


