#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    worldPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    running = run_texture;

    width = texture.width / maxFrames;
    height = texture.height;
    speed = 3.5f;
}

void Enemy::tick(float deltaTime){

    if (!getAlive()) return;
    
    // get to target
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
    if (Vector2Length(velocity) < radius) velocity = {};
    
    
    screenPos = Vector2Subtract(worldPos, target->getWorldPos());
    BaseCharacter::tick(deltaTime);

    if (CheckCollisionRecs(target->getCollisionRec(), getCollisionRec()))
    {
        target->takeDamage(damagePerSec * deltaTime);
    }
    

}

Vector2 Enemy::getScreenPos(){
    return Vector2Subtract(worldPos, target->getWorldPos());
}