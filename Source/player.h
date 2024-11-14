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
        float moveSpeed;
        float rotation;
        float rotationSpeed;

};