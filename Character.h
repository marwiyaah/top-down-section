#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter {
private:
    

public:
    Character(int winWidth, int winHeight);
    virtual void tick(float deltaTime) override;
    Vector2 getScreenPos(){ return screenPos; }
};

#endif CHARACTER_H

