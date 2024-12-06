#include "enemySpawner.h"


EnemySpawner::EnemySpawner(float interval, std::vector<Enemy*>& enemyList)
    : enemySpawnTimer(0.f),
      enemySpawnInterval(interval),
      enemies(enemyList)
{
}

void EnemySpawner::update(float deltaTime)
{
    enemySpawnTimer += deltaTime;

    if (enemySpawnTimer >= enemySpawnInterval)
    {
        enemySpawnTimer = 0.f;
        enemies.push_back(new Enemy(GetScreenWidth(), GetScreenHeight()));
    }
}