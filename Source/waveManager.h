#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include "enemySpawner.h"
class WaveManager
{
public:
  WaveManager(EnemySpawner* enemySpawner, float waveDelay);
  void update(float deltaTime, const Vector2 &playerPosition);
  inline int getCurrentWave() const { return currentWave;}
  inline bool isWaveInProgress() const {return waveInProgress;}
  inline int getTimeRemaining() { return timeRemaining; }
private:
  EnemySpawner* enemySpawner;
  int currentWave;
  float waveTimer;
  bool waveInProgress;
  float waveDelay;
  int timeRemaining;
  int enemiesToSpawn;
};



#endif //WAVEMANAGER_H
