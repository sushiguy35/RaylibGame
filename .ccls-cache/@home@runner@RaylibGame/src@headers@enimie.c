#include "enimie.h"

// Define the enimie struct
Enimie enimies[MAX_ENIMIES];

// Define the CreateEnimie function
void CreateEnimie(int index, int StartX, int StartY, int speed) {

    // Define the enimie pointer
    Enimie* enim = &enimies[index];

    // Set the enimie values for the first time
    if (enim->direction == 0) { // direction is 0, so this enemy has not been initialized yet
        enim->x = StartX; // Set the x position
        enim->y = StartY; // Set the y position
        enim->direction = 1; // Start moving down
    }

    enim->y += enim->direction * speed; // Move the enimie up or down depending on the direction
    if (enim->y >= 400) { // If the enimie is at the bottom of the screen
        enim->direction = -1; // Start moving up
    } else if (enim->y <= 25) { // If the enimie is at the top of the screen
        enim->direction = 1; // Start moving down
    }

    // Draw the enimie
    DrawRectangle(enim->x, enim->y, 25, 25, RED);
}