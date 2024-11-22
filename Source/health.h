#pragma once
#include <raylib.h>

class Health{
    public: 
        Health();
        Health(int);
        int getHealth() const;
        void receiveDamage(int);
        void receiveHealth(int);
    private:
        int maxHealth;
        int currentHealth;

};