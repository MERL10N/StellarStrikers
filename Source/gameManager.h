#pragma once
#include "player.h"

class Game{
    public:
        Game();
        ~Game();
        void draw();
        void update();
        void handleInput();
    private: 
        Player player;
};