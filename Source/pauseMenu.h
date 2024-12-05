#pragma once
#include "raylib.h"

class PauseMenu {
private: 
    Rectangle resumeButton; 
    Rectangle homeButton; 
public: 
    PauseMenu(); 
    void handleInput(bool &resume, bool &goToHome); 
    void draw(); 



};