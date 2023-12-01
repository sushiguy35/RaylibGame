#include "enimie.h"

Enimie enimies[MAX_ENIMIES];

void CreateEnimie(int index, int StartX, int StartY) {
    Enimie* enim = &enimies[index];

    if (enim->direction == 0) { // direction is 0, so this enemy has not been initialized yet
        enim->x = StartX;
        enim->y = StartY;
        enim->direction = 1; // Start moving down
    }

    enim->y += enim->direction * 10;
    if (enim->y >= 400) {
        enim->direction = -1; // Start moving up
    } else if (enim->y <= 25) {
        enim->direction = 1; // Start moving down
    }

    DrawRectangle(enim->x, enim->y, 25, 25, RED);
}