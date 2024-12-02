//
// Created by Kian Marvi on 11/29/24.
//

#include "rocket.h"
Rocket::Rocket(const Vector2 &position, float rotation)
    : Projectile(position, rotation, 300.0f, 3.0f, ASSETS_PATH "rocket.png"),
    hasExploded(false),
    explosionAnimation(ASSETS_PATH "explosion.png", 16, 1, 24)

{
}

Rocket::~Rocket()
{
}


bool Rocket::Update(float deltaTime)
{
    if (!isActive())
    {
        if (!hasExploded)
        {
            hasExploded = true;
            // Adjust explosion position with offsets
            float offsetX = 100.0f; // Adjust horizontally (positive moves right)
            float offsetY = 100.0f; // Adjust vertically (positive moves down)
            explosionPosition = { position.x + offsetX, position.y + offsetY };
            explosionAnimation.Start(explosionPosition); // Start the explosion animation
        }

        explosionAnimation.Update();

        return explosionAnimation.IsActive(); // Keep rocket alive until animation finishes
    }

    return Projectile::Update(deltaTime); // Update rocket while active
}

void Rocket::Render() const
{
    if (isActive())
    {
        Projectile::Render(); // Render the rocket if it’s active
    }
    else if (hasExploded)
    {
        explosionAnimation.Draw(explosionPosition, 1.5f); // Draw the explosion
    }
}

