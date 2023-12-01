#include "./headers/player.h"
#include <stdlib.h>
#include "raylib.h"

Player player;

bool run = true;

void died()
{
    DrawRectangle(0,0, 800, 450, BLACK);
    DrawText("You Died", 400, 225, 30, WHITE);
    run = false;
    InitWindow(600, 600, "LOSE");
    while(!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("You Died", 300, 300, 30, WHITE);
            DrawText("Press R to restart", 300, 350, 30, WHITE);
            if (IsKeyPressed(KEY_R))
            {
                CloseWindow();
                run = true;
                system("./main.exe");
            }
        EndDrawing();
    }
    CloseWindow();
}   