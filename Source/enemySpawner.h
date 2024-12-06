#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H
#include "Enemy.h"
class EnemySpawner
{
    public:
      EnemySpawner(float interval, std::vector<Enemy*> &enemies);
      void update(float deltaTime);

    private:
    float enemySpawnTimer;
    float enemySpawnInterval;
    std::vector<Enemy*> &enemies;
};



#endif //ENEMYSPAWNER_H
