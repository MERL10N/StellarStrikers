#include "gameManager.h"

Game::Game(){}

Game::~Game(){}

void Game::draw() {
    player.draw();
}

void Game::handleInput(){
    if(IsKeyDown(KEY_W)){
        player.moveForward();
    }
    if(IsKeyDown(KEY_S)){
        player.moveBackward();
    }
    if(IsKeyDown(KEY_A)){
        player.moveLeft();
    }
    if(IsKeyDown(KEY_D)){
        player.moveRight();
    }

}