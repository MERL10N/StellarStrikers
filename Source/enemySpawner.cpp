#include "enemySpawner.h"


EnemySpawner::EnemySpawner(float interval)
    : enemySpawnTimer(0.f),
      enemySpawnInterval(interval)
{
}

EnemySpawner::~EnemySpawner()
{
   for (auto enemy: enemies)
   {
     if (enemy)
      delete enemy;
   }

   if (!enemies.empty())
       enemies.clear();
}

void EnemySpawner::setEnemiesToSpawn(int count)
{
  enemiesToSpawn = count;
}

void EnemySpawner::update(float deltaTime, const Vector2 &playerPosition)
{
    enemySpawnTimer += deltaTime;

    if (enemies.size() < enemiesToSpawn && enemySpawnTimer >= enemySpawnInterval)
    {
        enemySpawnTimer = 0.f;

       for (int i = 0; i < enemiesToSpawn; ++i)
        enemies.push_back(new Enemy(GetScreenWidth(), GetScreenHeight()));
    }

    // Update existing enemies
    for (auto it = enemies.begin(); it != enemies.end();)
    {
        (*it)->Update(deltaTime, playerPosition);

        if (!(*it)->IsAlive())
        {
            delete (*it);
            it = enemies.erase(it);
        } else {
            ++it;
        }
    }
}

void EnemySpawner::draw()
{
    for (auto enemy: enemies)
    {
        enemy->Render();
    }
}

void EnemySpawner::reset()
{
    for (auto enemy: enemies)
    {
        delete enemy;
    }

    enemies.clear();
    enemySpawnTimer = 0.f;
}