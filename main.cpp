#include "raylib.h"


int main(){
    const int windowHeight{384};
    const int windowWidth{384};
    InitWindow(windowWidth, windowHeight, "Top Down");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
       BeginDrawing();
       ClearBackground(WHITE);

       Vector2 mapPos{0.0, 0.0};
       DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

       EndDrawing();
    }
    CloseWindow();

}

// upto 4.2 -> 9/7/2025