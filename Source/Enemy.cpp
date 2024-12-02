#include "Enemy.h"

#include <raymath.h>

Enemy::Enemy()
{
}

Enemy::Enemy(const Vector2& position, float &screenWidth,  float &screenHeight)
: position(position),
  screenWidth(screenWidth),
  screenHeight(screenHeight),
  currentState(State::CHASE),
  alive(true),
  shootTimer(0.0f),
  shootCooldown(2.0f),
  dieTimer(1.0f)
{
    texture = LoadTexture(ASSETS_PATH"enemy.png");
    origin = {texture.width * 0.5f, texture.height * 0.5f};

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

void Enemy::Update(float &deltaTime, const Vector2 &position)
{
    if (!alive)
        return;

    switch (currentState)
        {
        case State::CHASE:
            UpdateChase(position, deltaTime);
            break;
        case State::SHOOT:
            UpdateShoot(deltaTime);
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

}

void Enemy::UpdateShoot(float &deltaTime)
{
    velocity = {0.0f, 0.0f};

    shootTimer += deltaTime;

    if (shootTimer >= shootCooldown) {
        shootTimer = 0.0f;


    }
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
    DrawTexturePro(texture, sourceRect, destinationRect, center, 0.0f, WHITE);
}



