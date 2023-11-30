#include "raylib.h"

#ifndef PLAYER_H
#define PLAYER_H
typedef struct PLAYER {
    int x, y, width, height;
    Rectangle rec;
} Player;

extern Player player;

#endif