
#include "waveManager.h"
#include <iostream>
#include <string>

WaveManager::WaveManager(EnemySpawner* enemySpawner, float waveDelay)
   : enemySpawner(enemySpawner),
     waveTimer(0.0f),
     currentWave(0),
     waveInProgress(false),
     waveDelay(waveDelay),
     enemiesToSpawn(1)
{
}


void WaveManager::update(float deltaTime, const Vector2 &playerPosition)
{
    if (!waveInProgress)
    {
        waveTimer += deltaTime;

        if (waveTimer >= waveDelay)
        {
            std::cout << "[WaveManager] Starting Wave " << currentWave << "!\n";
            waveTimer = 0.0f;
            waveInProgress = true;
            currentWave++;
            enemiesToSpawn += 2;
            enemySpawner->setEnemiesToSpawn(enemiesToSpawn);
            enemySpawner->reset();

        }
    }

    if (waveInProgress && enemySpawner->getEnemies().empty())
    {
            enemySpawner->update(deltaTime, playerPosition);
    }



}