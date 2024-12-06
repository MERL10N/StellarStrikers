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

void Health::receiveDamage(int damage) {
    currentHealth = std::max(0, currentHealth - damage);
}
         
void Health::receiveHealth(int received_health){
    currentHealth = std::min(maxHealth, currentHealth + received_health);
}

void Health::resetHealth() {
    currentHealth = maxHealth; 
}