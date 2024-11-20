#include "bullet.h"
#include <math.h>

bullet::bullet(Vector2 position, float rotation): 
  position(position),
  speed(500),
  rotation(rotation),
  bulletLife(2.0f),
  creationTime(GetTime()),
  active(true),
  bulletTexture(LoadTexture(ASSETS_PATH "playerbullet.png"))
{}

bool bullet::update(float frameTime){
    if(!active || (GetTime() > creationTime + bulletLife)){
        active = false;
        UnloadTexture(bulletTexture);
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
