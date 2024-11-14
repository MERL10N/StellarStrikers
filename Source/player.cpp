#include "player.h"
#include <cmath>

Player::Player(){
    playerSprite = LoadTexture(ASSETS_PATH "player.png"); 
    position.x = 100.f;
    position.y = 250.f;
    rotation = 0.0f;
    rotationSpeed = 4.0f;
    moveSpeed = 3.0f;
    lastFireTime = 0.0;
}

Player::~Player(){
    UnloadTexture(playerSprite);
}

void Player::moveForward(){
    position.x += sin(rotation * DEG2RAD) * moveSpeed;
    position.y -= cos(rotation * DEG2RAD) * moveSpeed;
}

void Player::moveBackward(){
    position.x -= sin(rotation * DEG2RAD) * moveSpeed;
    position.y += cos(rotation * DEG2RAD) * moveSpeed;
}

void Player::moveLeft(){
    rotation -= rotationSpeed;
    if(rotation < 0) rotation += 360.0f;
}

void Player::moveRight(){
    rotation += rotationSpeed;
    if(rotation >= 360.0f) rotation -= 360.0f;
}

void Player::fireBullet(){
    if(GetTime() - lastFireTime >= 0.35){
        Vector2 bulletPosition = {position.x, position.y};
        bulletsVector.push_back(bullet(bulletPosition, rotation));
        lastFireTime = GetTime();
    }
}

void Player::draw(){
    // Get the center of the player sprite
    Vector2 center = { playerSprite.width * 0.025f, playerSprite.height * 0.025f };

    // Define the destination rectangle for positioning and scaling
    Rectangle destination = 
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
}