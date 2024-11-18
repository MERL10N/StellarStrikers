#pragma once
#include <raylib.h>

class bullet{
public:
    bullet(Vector2 position, float rotation);
    bool update(float frameTime);
    void draw();
    bool active;

private:
    Vector2 position;
    int speed;
    float rotation;
    float creationTime;
    float bulletLife;
    Texture2D bulletTexture;
};
