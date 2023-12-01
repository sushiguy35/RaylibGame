#include <stdio.h>
#include "raylib.h"

typedef struct Position {
    int x;
    int y;
} Position;

Position CreateEnimie(int StartX, int StartY)
{
    Position pos;
    pos.y = GetRandomValue(40, 410);
    pos.x = GetRandomValue(40, 760);
    DrawRectangle(pos.x, pos.y, 25, 25, RED);
    return pos;
}