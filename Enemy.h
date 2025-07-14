#include "raylib.h"
#include "BaseCharacter.h"

class Enemy : public BaseCharacter 
{
private:

public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    virtual void tick(float deltaTime) override;
};
