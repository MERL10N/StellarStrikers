#pragma once
#include <raylib.h>
#include "bullet.h"
#include <vector>

class Player{
    public: 
        Player();
        ~Player();
        void draw();
        void moveLeft();
        void moveRight();
        void moveForward();
        void moveBackward();
        void fireBullet();
        std::vector<bullet> bulletsVector;
    private:
        Texture2D playerSprite;
        Vector2 position;
        float moveSpeed;
        float rotation;
        float rotationSpeed;
        double lastFireTime;
};