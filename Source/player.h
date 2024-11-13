#pragma once
#include <raylib.h>

class Player{
    public: 
        Player();
        ~Player();
        void draw();
        void moveLeft();
        void moveRight();
        void moveForward();
        void moveBackward();
    private:
        Texture2D playerSprite;
        Vector2 position;
        Vector2 speed;
        float moveSpeed;
        float rotation;
        float rotationSpeed;
        //float angle = 0.0f;
        //float rotationSpeed = 3.0f;
};