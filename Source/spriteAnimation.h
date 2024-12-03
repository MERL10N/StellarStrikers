#ifndef SPRITE_ANIMATION_H
#define SPRITE_ANIMATION_H

#include "raylib.h"

class SpriteAnimation
{
public:
    // Constructor
    SpriteAnimation(const char* filePath, int framesPerLine, int numLines, int fps);

    // Destructor
    ~SpriteAnimation();

    // Update the animation
    void Update();

    // Draw the current frame
    void Draw(const Vector2 &position, float scale = 1.0f, Color tint = WHITE) const;

    // Start the animation
    void Start(Vector2 startPosition);

    // Check if the animation is active
    bool IsActive() const;

    // Reset the animation
    void Reset();

private:
    Texture2D texture;         // Texture containing the sprite sheet
    Rectangle frameRec;        // Rectangle for the current frame
    Vector2 position;          // Position to draw the animation
    int framesPerLine;         // Number of frames per line in the sprite sheet
    int numLines;              // Number of lines in the sprite sheet
    int fps;                   // Frames per second
    int currentFrame;          // Current frame index
    int currentLine;           // Current line index
    int framesCounter;         // Frame counter for timing
    float frameWidth = 2048 / 16; // 128 pixels
    float frameHeight = 128;      // Full height
    bool active;               // Whether the animation is active
};

#endif // SPRITE_ANIMATION_H