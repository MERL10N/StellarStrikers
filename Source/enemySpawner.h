#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H
#include "Enemy.h"
class EnemySpawner
{
   public:
    EnemySpawner(float interval);
    ~EnemySpawner();
    void setEnemiesToSpawn(int count);
    void update(float deltaTime, const Vector2 &playerPosition);
    void draw();
    void reset();
    std::vector<Enemy*>& getEnemies() { return enemies; }

   private:
    int enemiesToSpawn;
    float enemySpawnTimer;
    float enemySpawnInterval;
    std::vector<Enemy*> enemies;
};



#endif //ENEMYSPAWNER_H
