// neccessary includes
#include "./headers/player.h"
#include <stdlib.h>
#include "raylib.h"
#include "headers/menu.h"

// define the player object
Player player;

// define the run variable
bool run = true;

// define the died function
void died()
{
    // return to main menu when the player died
    gameState = PLAYER_DEAD;
}   
