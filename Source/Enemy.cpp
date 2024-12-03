#include "Enemy.h"

#include <iostream>
#include <raymath.h>

Enemy::Enemy()
{
}

Enemy::Enemy(float screenWidth,  float screenHeight)
:
  texture(LoadTexture(ASSETS_PATH"enemy.png")),
  position(position),
  screenWidth(screenWidth),
  screenHeight(screenHeight),
  currentState(State::CHASE),
  alive(true),
  shootTimer(0.0f),
  shootCooldown(2.0f),
  dieTimer(1.0f),
  speed(100.0f),
  rotation(0.0f),
  shootingRange(200.f)
{
    origin = {texture.width * 0.0025f, texture.height * 0.0025f};

    Spawn(screenWidth, screenHeight);
}

Enemy::~Enemy()
{
    UnloadTexture(texture);
}

void Enemy::Spawn(float &screenWidth, float &screenHeight)
{
    // Randomly pick an edge of the screen between 0-3;
    int edgeOfScreen = GetRandomValue(0, 3);

    switch (edgeOfScreen)
        {
        case 0:
            position = {(float)GetRandomValue(0, screenWidth), (float)-texture.height}; // Spawn on the top edge of the screen
            break;
        case 1:
            position = {(float)GetRandomValue(0, screenWidth), screenHeight + (float)texture.height};
            break;
        case 2:
            position = {-(float)texture.width, (float)GetRandomValue(0, screenHeight)};
            break;
        case 3:
            position = {screenWidth + (float)texture.width, (float)GetRandomValue(0, screenHeight)};
            break;
    }
}

void Enemy::Update(float &deltaTime, const Vector2 &playerPosition)
{
    if (!alive)
        return;

    float distance = Vector2Distance(position, playerPosition);

    if (distance <= shootingRange)
      currentState = State::SHOOT;
    else
      currentState = State::CHASE;

    switch (currentState)
        {
        case State::CHASE:
            UpdateChase(playerPosition, deltaTime);
            break;
        case State::SHOOT:
            UpdateShoot(playerPosition, deltaTime);
            break;
        case State::DIE:
            UpdateDie(deltaTime);
            break;
    }
}

void Enemy::UpdateChase(const Vector2 &playerPosition, float deltaTime)
{

    // Calculate direction vector to player
    Vector2 direction = {playerPosition.x - position.x, playerPosition.y - position.y};


    // Normalise direction
    direction = Vector2Normalize(direction);


    // Set velocity towards the player
    velocity = {direction.x * speed, direction.y * speed};


    // Update the position using kinematics equation
    position += velocity * deltaTime;

    // Calculate rotation to face the player
    rotation = atan2(direction.y, direction.x) * RAD2DEG;

}

void Enemy::UpdateShoot(const Vector2 &playerPosition, float &deltaTime)
{
      velocity = Vector2Zero();

      shootTimer += deltaTime;

      if (shootTimer >= shootCooldown)
      {
         shootTimer = 0.0f;

          bulletsVector.push_back(std::make_unique<Bullet>(position, rotation + 90));
      }

    // Update bullets
    for (auto& bullet : bulletsVector) {
        bullet->Update(deltaTime);
    }
    if (Vector2Distance(position, playerPosition) > shootingRange)
    {
        currentState = State::CHASE;
    }
  CleanUpBullets();
}

void Enemy::UpdateDie(float &deltaTime) {

}


void Enemy::Render() const
{
    if (!alive)
        return;

    // Get the center of the enemy sprite
    Vector2 center = { texture.width * 0.025f, texture.height * 0.025f };

    // Define the destination rectangle for positioning and scaling
    Rectangle destinationRect = { position.x, position.y, texture.width * 0.05f, texture.height * 0.05f};

    // Define the source rectangle for the texture
    Rectangle sourceRect = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };

    // Draw the player sprite with rotation around its center
    BeginBlendMode(BLEND_ALPHA);
    DrawTexturePro(texture, sourceRect, destinationRect, center, rotation - 90, WHITE);
    EndBlendMode();

    for (const auto& bullet : bulletsVector)
    {
        bullet->Render();
    }
}

void Enemy::CleanUpBullets()
{
  for (auto it = bulletsVector.begin(); it != bulletsVector.end();)
   {
        if (!(*it)->isActive())
        {
            it = bulletsVector.erase(it);
        }
        else
        {
            it++;
        }
   }

}
