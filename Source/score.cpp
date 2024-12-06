#include "score.h"

#include <iostream>


void Score::addscore(){
    currentScore = currentScore + 100;
}

int Score::viewScore(){
    return currentScore;
}
