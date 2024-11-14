#include "gameManager.h"

Game::Game(){}

Game::~Game(){}

void Game::update(){
    for(auto& bullet : player.bulletsVector){
        bullet.update(GetFrameTime());
    }
    DeleteInactiveBullets();
}

void Game::draw(){
    player.draw();
    for(auto& bullet : player.bulletsVector){
        bullet.draw();
    }
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
    if(IsKeyDown(KEY_SPACE)){
        player.fireBullet();
    }
}

void Game::DeleteInactiveBullets(){
    for(int i = 0; i < player.bulletsVector.size(); ++i){
        if(!player.bulletsVector[i].active){
            player.bulletsVector.erase(player.bulletsVector.begin() + i);
            --i;
        }
    }
}