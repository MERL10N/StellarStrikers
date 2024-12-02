
#ifndef ENEMY_H
#define ENEMY_H
#include <raylib.h>

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
    Enemy(const Vector2& position, float &screenWidth, float &screenHeight);
    ~Enemy();

    void Update(float &deltaTime, const Vector2& position);
    void Render() const;

    inline bool IsAlive() const { return alive; }

    private:
      bool alive;
      Vector2 position;
      Vector2 velocity;
      float speed;
      State currentState;

      Texture2D texture;
      Vector2 origin;

      float screenWidth;
      float screenHeight;

      float shootTimer;
      float shootCooldown;
      float dieTimer;

      void Spawn(float &screenWidth, float &screenHeight);
      void UpdateChase(const Vector2& playerPosition, float deltaTime);
      void UpdateShoot(float &deltaTime);
      void UpdateDie(float &deltaTime);
};



#endif //ENEMY_H
