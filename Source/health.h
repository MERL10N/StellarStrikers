#pragma once

class Health
{
    public: 
        Health();
        Health(int);
        int getHealth() const;
        void receiveDamage();
        void receiveHealth(int);
    private:
        int maxHealth;
        int currentHealth;

};