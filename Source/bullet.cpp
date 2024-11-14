#include "bullet.h"
#include <math.h>

bullet::bullet(Vector2 position, float rotation){
    this->position = position;
    this->speed = 500;
    this->rotation = rotation;
    this->bulletLife = 2.0f;
    this->creationTime = GetTime();
    this->active = true;
    bulletTexture = LoadTexture(ASSETS_PATH "playerbullet.png");
}

bool bullet::update(float frameTime){
    if(!active || (GetTime() > creationTime + bulletLife)){
        active = false;
        return false;
    }

    position.x += speed * frameTime * sin(rotation * DEG2RAD);
    position.y -= speed * frameTime * cos(rotation * DEG2RAD);
    return true;
}

void bullet::draw(){
    if(active){
        DrawTextureEx(bulletTexture, position, rotation - 90, 0.02, WHITE);
    }
}
