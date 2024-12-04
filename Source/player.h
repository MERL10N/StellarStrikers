#pragma once
#include "projectile.h"
#include "bullet.h"
#include "rocket.h"
#include "raylib.h"
#include <cmath>
#include <vector>
#include "health.h"

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
        inline Vector2 getPosition() { return position; }
        std::vector<Projectile*> bulletsVector;
        int getHealth() const { return health.getHealth(); }
        void receiveDamage(int damage) { health.receiveDamage(damage); }
        Rectangle getHitBox() const;
        void playHitSound() const;
    private:
        Texture2D playerSprite;
        Health health;
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
        Sound hitSFX;
};