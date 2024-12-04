#include "player.h"
#include <iostream>

Player::Player()
: position(Vector2{100.f, 250.f}),
  rotation(0.0f),
  rotationSpeed(4.0f),
  moveSpeed(3.0f),
  targetRotation(0.0f),
  playerSprite(LoadTexture(ASSETS_PATH"player.png")),
  rotationSpeedMultiplier(10.f),
  bulletSFX(LoadSound(ASSETS_PATH "bulletSFX.mp3")),
  hitSFX(LoadSound(ASSETS_PATH "hitSFX.mp3")),
  angleDifference(0.0f),
  lastFireTime(0.0),
  fireRateMultiplier(1.0f),
  health(100) 
{
}

Player::~Player()
{
    UnloadTexture(playerSprite);
    UnloadSound(bulletSFX);
    UnloadSound(hitSFX);
}

void Player::draw()
{
    // Get the center of the player sprite
    Vector2 center = { playerSprite.width * 0.025f, playerSprite.height * 0.025f };

    // Define the destination rectangle for positioning and scaling
    destination = 
    {
        position.x,                          
        position.y,                         
        playerSprite.width * 0.05f,          
        playerSprite.height * 0.05f         
    };

    // Define the source rectangle for the texture
    Rectangle source = { 0.0f, 0.0f, (float)playerSprite.width, (float)playerSprite.height };

    // Draw the player sprite with rotation around its center
    DrawTexturePro(playerSprite, source, destination, center, rotation, WHITE);
    DrawText(TextFormat("Health: %d", health.getHealth()), position.x - 20, position.y - 40, 20, GREEN);
}

void Player::moveForward()
{
    position.x += sin(rotation * DEG2RAD) * moveSpeed;
    position.y -= cos(rotation * DEG2RAD) * moveSpeed;

    if (position.x < 0) position.x = 0;
    if (position.x > GetScreenWidth()) position.x = GetScreenWidth();
    if (position.y < 0) position.y = 0;
    if (position.y > GetScreenHeight()) position.y = GetScreenHeight();
}

void Player::moveBackward()
{
    position.x -= sin(rotation * DEG2RAD) * moveSpeed;
    position.y += cos(rotation * DEG2RAD) * moveSpeed;

    if (position.x < 0) position.x = 0;
    if (position.x > GetScreenWidth()) position.x = GetScreenWidth();
    if (position.y < 0) position.y = 0;
    if (position.y > GetScreenHeight()) position.y = GetScreenHeight();
}

void Player::moveLeft()
{
    rotation -= rotationSpeed;
    if(rotation < 0) rotation += 360.0f;
}

void Player::moveRight()
{
    rotation += rotationSpeed;
    if(rotation >= 360.0f) rotation -= 360.0f;
}

void Player::moveWithController(const float &axisX, const float &axisY)
{
   // Update rotation only when the left thumbstick is in use
    if (axisX != 0.0f || axisY != 0.0f)
    {
        // Compute the target angle
        targetRotation = atan2(axisY, axisX) * RAD2DEG + 90.f;    

        // Keep targetRotation within the range [0,360)
        if (targetRotation < 0)
            targetRotation += 360.f;

        if (targetRotation >= 360.0f)
            targetRotation -= 360.0f;

        // Compute the shortest angle difference and keep it within the range [0, 360)
        angleDifference = fmod((targetRotation - rotation) + 360.f, 360.f);
        if (angleDifference > 180.0f)
           angleDifference -= 360.0f;
        

        rotation += (angleDifference) / rotationSpeedMultiplier;
 
        // Keep rotation within the range [0,360)
        if (rotation < 0)
            rotation += 360.f;

        if (rotation >= 360.0f)
            rotation -= 360.0f;

    }

    position.x += sin(rotation * DEG2RAD) * moveSpeed;
    position.y -= cos(rotation * DEG2RAD) * moveSpeed;

    if (position.x < 0) position.x = 0;
    if (position.x > GetScreenWidth()) position.x = GetScreenWidth();
    if (position.y < 0) position.y = 0;
    if (position.y > GetScreenHeight()) position.y = GetScreenHeight();
}
void Player::setFireRate(const float &fireRateMultiplier)
{
    this->fireRateMultiplier = fireRateMultiplier;
}
void Player::fireBullet()
{
    if(GetTime() - lastFireTime >= (0.35 / fireRateMultiplier)){
        Vector2 bulletPosition = {position.x, position.y};
        bulletsVector.push_back(new Bullet(bulletPosition, rotation));
        lastFireTime = GetTime();
        PlaySound(bulletSFX);
    }
}

void Player::fireRocket()
{
    if(GetTime() - lastFireTime >= (2 / fireRateMultiplier))
    {
        Vector2 bulletPosition = {position.x, position.y};
        bulletsVector.push_back(new Rocket(bulletPosition, rotation));
        lastFireTime = GetTime();
    }
}


Rectangle Player::getDestination()
{
    return destination;
}


Rectangle Player::getHitBox() const {
    return {position.x - 35.025f, position.y - 36.225f, 70.05f, 72.45f}; 
}

void Player::playHitSound() const {
    PlaySound(hitSFX);
}