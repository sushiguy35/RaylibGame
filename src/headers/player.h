#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct Player {
    Rectangle rec;
    int x;
    int y;
    int width;
    int height;
} Player;

extern Player player;
extern bool run;

void died();
void resetPlayer();

#endif // PLAYER_H