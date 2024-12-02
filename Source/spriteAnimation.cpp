#include "spriteAnimation.h"

SpriteAnimation::SpriteAnimation(const char* filePath, int framesPerLine, int numLines, int fps)
    : framesPerLine(framesPerLine), numLines(numLines), fps(fps),
      currentFrame(0), currentLine(0), framesCounter(0), active(false)
{
    // Load the texture
    texture = LoadTexture(filePath);

    // Validate the texture
    if (texture.width == 0 || texture.height == 0) {
        TraceLog(LOG_ERROR, "Failed to load texture: %s", filePath);
        frameWidth = 0;
        frameHeight = 0;
        frameRec = {0.0f, 0.0f, 0.0f, 0.0f};
        return; // Exit if texture loading fails
    }

    // Calculate frame dimensions
    frameWidth = static_cast<float>(texture.width) / framesPerLine;
    frameHeight = static_cast<float>(texture.height) / numLines;
    frameRec = {0.0f, 0.0f, frameWidth, frameHeight};

    // Debug log for successful initialization
    TraceLog(LOG_INFO, "SpriteAnimation initialized: filePath = %s, frameWidth = %f, frameHeight = %f",
             filePath, frameWidth, frameHeight);
}

SpriteAnimation::~SpriteAnimation()
{
    UnloadTexture(texture);
}

void SpriteAnimation::Update() {
    if (!active) return;

    framesCounter++;
    if (framesCounter >= (60 / fps)) {
        currentFrame++;

        if (currentFrame >= framesPerLine) {
            currentFrame = 0;
            currentLine++;

            if (currentLine >= numLines) {
                currentLine = 0;
                active = false; // Animation has finished
            }
        }

        framesCounter = 0;
    }

    frameRec.x = frameWidth * currentFrame;
    frameRec.y = frameHeight * currentLine;
    TraceLog(LOG_INFO, "FrameRec updated: x=%f, y=%f, width=%f, height=%f", frameRec.x, frameRec.y, frameRec.width, frameRec.height);
}

void SpriteAnimation::Draw(const Vector2 &position, float scale, Color tint) const
{
    if (active)
        {
        // Calculate destination rectangle for the animation
        Rectangle destRec =
            {
            position.x - (frameWidth * scale) * 0.5f, // Center horizontally
            position.y - (frameHeight * scale) * 0.5f, // Center vertically
            frameWidth * scale, // Scaled width
            frameHeight * scale // Scaled height
        };

        // Set origin to the center of the sprite
        Vector2 origin = { frameWidth * scale * 0.5f, frameHeight * scale * 0.5f };

        // Draw the current frame
        DrawTexturePro(texture, frameRec, destRec, origin, 0.0f, tint);
    }
}

void SpriteAnimation::Start(Vector2 startPosition)
{
    position = startPosition;
    currentFrame = 0;
    currentLine = 0;
    framesCounter = 0;
    active = true;
}

bool SpriteAnimation::IsActive() const
{
    return active;
}

void SpriteAnimation::Reset()
{
    currentFrame = 0;
    currentLine = 0;
    framesCounter = 0;
    active = false;
}