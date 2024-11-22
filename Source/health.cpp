#include "health.h"
#include <algorithm>

Health::Health(){
    currentHealth = 100;
    maxHealth = 100;
}

Health::Health(int givenHealth){
    currentHealth = givenHealth;
    maxHealth = givenHealth;
}

int Health::getHealth() const{
    return currentHealth;
}

void Health::receiveDamage(){
    currentHealth = std::max(0, currentHealth - 10);
}
         
void Health::receiveHealth(int received_health){
    currentHealth = std::min(maxHealth, currentHealth + received_health);
}