#pragma once
#include "projectile.h"
#include "bullet.h"
#include "rocket.h"
#include <vector>

class Player
{
    public: 
        Player();
        ~Player();
        void draw();
        void moveLeft();
        void moveRight();
        void moveForward();
        void moveBackward();
        void moveWithController(const float &axisX, const float &axisY);
        void fireBullet();
        void fireRocket();
        void setFireRate(const float &fireRateMultiplier);
        Rectangle getDestination();
        std::vector<Projectile*> bulletsVector;
    private:
        Texture2D playerSprite;
        Vector2 position;
        float moveSpeed;
        float rotation;
        float rotationSpeed;
        float targetRotation;
        float rotationSpeedMultiplier;
        float angleDifference;
        Rectangle destination;
        double lastFireTime;
        float fireRateMultiplier;
        Sound bulletSFX;
};