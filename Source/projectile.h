//
// Created by Kian Marvi on 11/29/24.
//

#pragma once

#include <raylib.h>

class Projectile
{
public:
  Projectile(const Vector2& position, float rotation, float speed, float lifespan, const char* texturePath);
  virtual ~Projectile() = default ;

  virtual bool Update(float deltaTime);

  virtual void Render() const;

  bool isActive() const { return active; }

  Vector2 getPosition() const { return position; }

  Rectangle getHitBox() const;

  void Deactivate() { active = false; }

protected:
  Vector2 position;
  float speed;
  float rotation;
  float lifespan;
  float creationTime;
  bool active;
  const char* texturePath;
  Texture2D texture;
};



