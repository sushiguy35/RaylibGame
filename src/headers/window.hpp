#include "raylib.h"
#include "../draw.cpp"

class Window {
public:
    void init()
    {
        InitWindow(800, 450, "raylib [core] example - basic window");

        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            draw.player(player);  // Pass the player object to the draw function
            EndDrawing();
        }

        CloseWindow();
    }
};
