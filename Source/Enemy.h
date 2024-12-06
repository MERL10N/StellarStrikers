#pragma once
#include <raylib.h>

#include "projectile.h"
#include <vector>
#include "health.h"
#include "spriteAnimation.h"
#include <memory>

class Enemy
{
public:
  enum class State
   {
        CHASE,
        SHOOT,
        DIE
    };
    Enemy();
    Enemy(float screenWidth, float screenHeight);
    ~Enemy();

    void Update(const float &deltaTime, const Vector2& position);
    void Render();

    inline bool IsAlive() const { return alive; }
    inline bool getHasExploded() const { return hasExploded; }
    inline Health& getHealthComponent() { return health; }
    inline void setState(State newState) { currentState = newState; }
    inline State getState() { return currentState; }
    Rectangle getHitBox() const; 

    std::vector<Projectile*> getBullets();
    void reset();



    private:
      bool alive;
      bool hasExploded{};
      Vector2 position{};
      Vector2 velocity{};
      float speed{};
      State currentState;
      Health health;

      std::vector<std::unique_ptr<Projectile>> bulletsVector;

      Texture2D texture{};
      Vector2 origin{};

      float screenWidth{};
      float screenHeight{};

      float shootTimer{};
      float shootCooldown{};
      float dieTimer{};
      float shootingRange{};

      SpriteAnimation explosionAnimation;
      Vector2 explosionPosition{};

      float rotation{};

      void Spawn(const float &screenWidth, const float &screenHeight);
      void UpdateChase(const Vector2& playerPosition, float deltaTime);
      void UpdateShoot(const Vector2 &playerPosition, const float &deltaTime);
      void Despawn();
      void CleanUpBullets();
};


