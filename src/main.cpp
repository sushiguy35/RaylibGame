#include "raylib.h"
#include <iostream>
#include "player.cpp"
#include "deltatime.cpp"

#define SCREENWIDTH 800
#define SCREENHEIGHT 450

int main(void)
{
    Player player;
  
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib [core] example - basic window");
    player.x = 100;
    player.y = 50;
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(player.x, player.y, 25, 50, RED);


            if (IsKeyDown(KEY_RIGHT)) player.x += 5 * deltatime();
            if (IsKeyDown(KEY_LEFT)) player.x -= 5 * deltatime();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}