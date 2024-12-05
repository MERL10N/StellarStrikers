#include "Enemy.h"
#include "bullet.h"
#include <iostream>
#include <raymath.h>

Enemy::Enemy():
explosionAnimation(ASSETS_PATH "explosion.png", 16, 1, 24)
{
}

Enemy::Enemy(float screenWidth,  float screenHeight)
:
  alive(true),
  hasExploded(false),
  position{Vector2Zero()},
  speed(100.0f),
  currentState(State::CHASE),
  health(50),
  texture(LoadTexture(ASSETS_PATH"enemy.png")),
  screenWidth(screenWidth),
  screenHeight(screenHeight),
  shootTimer(0.0f),
  shootCooldown(2.0f),
  dieTimer(1.0f),
  shootingRange(200.f),
  explosionAnimation( ASSETS_PATH"explosion.png", 16, 1, 24),
  rotation(0.0f)
{
    origin = {texture.width * 0.0025f, texture.height * 0.0025f};

    Spawn(screenWidth, screenHeight);
}

Enemy::~Enemy()
{
        UnloadTexture(texture);
}

void Enemy::Spawn(const float &screenWidth, const float &screenHeight)
{
    // Randomly pick an edge of the screen between 0-3;

    switch (GetRandomValue(0, 3))
        {
        case 0:
            position = {static_cast<float>(GetRandomValue(0, screenWidth)), static_cast<float>(-texture.height)}; // Spawn on the top edge of the screen
            break;
        case 1:
            position = {static_cast<float>(GetRandomValue(0, screenWidth)), screenHeight + static_cast<float>(texture.height)};
            break;
        case 2:
            position = {-static_cast<float>(texture.width), static_cast<float>(GetRandomValue(0, screenHeight))};
            break;
        case 3:
            position = {screenWidth + static_cast<float>(texture.width), static_cast<float>(GetRandomValue(0, screenHeight))};
            break;

    }
}

void Enemy::Update(const float &deltaTime, const Vector2 &playerPosition)
{


    float distance = Vector2Distance(position, playerPosition);

    if (distance <= shootingRange && alive)
      currentState = State::SHOOT;
    else if (distance > shootingRange && alive)
      currentState = State::CHASE;

    if (health.getHealth() == 0 && alive)
    {
        currentState = State::DIE;
        alive = false;
    }

    switch (currentState)
        {
        case State::CHASE:
            UpdateChase(playerPosition, deltaTime);
            break;
        case State::SHOOT:
            UpdateShoot(playerPosition, deltaTime);
            break;
        case State::DIE:
            alive = false;
            Despawn();
            break;
        default:
            UpdateChase(playerPosition, deltaTime);
            break;
        }

    // Update bullets
    for (auto& bullet : bulletsVector) {
        bullet->Update(deltaTime);
    }

    CleanUpBullets();
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

void Enemy::UpdateShoot(const Vector2 &playerPosition, const float &deltaTime)
{
      velocity = Vector2Zero();

      shootTimer += deltaTime;

      if (shootTimer >= shootCooldown)
      {
         shootTimer = 0.0f;

          bulletsVector.push_back(std::make_unique<Bullet>(position, rotation + 90));
      }


    if (Vector2Distance(position, playerPosition) > shootingRange)
    {
        currentState = State::CHASE;
    }
}

void Enemy::Despawn()
{
    if (!alive && !hasExploded)
    {
        hasExploded = true;
        // Adjust explosion position with offsets
        float offsetX = 100.0f; // Adjust horizontally (positive moves right)
        float offsetY = 100.0f; // Adjust vertically (positive moves down)
        explosionPosition = { position.x + offsetX, position.y + offsetY };
        explosionAnimation.Start(explosionPosition); // Start the explosion animation

    }

    if (hasExploded)
    {
        explosionAnimation.Update();
        if (!explosionAnimation.IsActive())
        {
            hasExploded = false;
        }
    }
}

void Enemy::Render()
{
    if (hasExploded)
    {
        explosionAnimation.Draw(explosionPosition, 1.5f); // Draw the explosion
        return;
    }

    // Get the center of the enemy sprite
    Vector2 center = { texture.width * 0.025f, texture.height * 0.025f };

    // Define the destination rectangle for positioning and scaling
    Rectangle destinationRect = { position.x, position.y, texture.width * 0.05f, texture.height * 0.05f};

    // Define the source rectangle for the texture
    Rectangle sourceRect = { 0.0f, 0.0f, static_cast<float>(texture.width), static_cast<float>(texture.height) };

    // Draw the player sprite with rotation around its center
    BeginBlendMode(BLEND_ALPHA);
    DrawTexturePro(texture, sourceRect, destinationRect, center, rotation - 90, WHITE);
    EndBlendMode();


    DrawText(TextFormat("Health: %d", health.getHealth()), position.x - 20, position.y - 40, 20, RED);

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
            ++it;
        }
   }

}

Rectangle Enemy::getHitBox() const {
    return {position.x - 31.475f, position.y - 33.725f, 62.95f, 67.45f};
}

std::vector<Projectile*> Enemy::getBullets() {
    std::vector<Projectile*> bulletPointers;
    bulletPointers.reserve(bulletsVector.size());
for (const auto& bullet : bulletsVector)
    {
        bulletPointers.push_back(bullet.get()); 
    }
    return bulletPointers;
}