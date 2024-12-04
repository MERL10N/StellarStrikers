#pragma once

class Health
{
    public: 
        Health();
        Health(int);
        int getHealth() const;
        void receiveDamage(int damage);
        void receiveHealth(int);
    private:
        int maxHealth;
        int currentHealth;

};