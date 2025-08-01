#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter(){

}

void BaseCharacter :: undoMovement(){
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getCollisionRec(){
    return Rectangle{
        getScreenPos().x,
        getScreenPos().y,
        width * scale,
        height * scale
    };
}

void BaseCharacter::tick(float deltaTime){
    worldPosLastFrame = worldPos;
    // update animation frame
       runningTime += GetFrameTime();   // running time +=  delta time (dt)
       if (runningTime >= updateTime)
       {    
            frame++;
            runningTime = 0.f;
            if (frame > maxFrames) frame = 0;
       }

       if (Vector2Length(velocity) != 0.0)
       {
        // set worldPos = worldPos + velocity
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = running;
       } else {
            texture = idle;
       }
       velocity = {};

       // draw the character
       Rectangle source{frame * width, 0.f, rightLeft * width, height};
       Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
       DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}