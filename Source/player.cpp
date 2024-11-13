#include "player.h"
#include <cmath>

Player::Player(){
    playerSprite = LoadTexture(ASSETS_PATH "player.png"); 
    position.x = 100.f;
    position.y = 250.f;
    speed = {0.0f, 0.0f};
    rotation = 0.0f;
    rotationSpeed = 4.0f;
    moveSpeed = 3.0f;
}

Player::~Player(){
    UnloadTexture(playerSprite);
}

void Player::draw(){
    DrawTextureEx(playerSprite, position, rotation, 0.05, WHITE);
}

void Player::moveForward(){
    position.x += sin(rotation * DEG2RAD) * moveSpeed;
    position.y -= cos(rotation * DEG2RAD) * moveSpeed;
}

void Player::moveBackward(){
    position.y += 2.0f; //placeholder may not exist
}

void Player::moveLeft(){
    rotation -= rotationSpeed;
    if(rotation < 0) rotation += 360.0f;
}

void Player::moveRight(){
    rotation += rotationSpeed;
    if(rotation >= 360.0f) rotation -= 360.0f;

}

