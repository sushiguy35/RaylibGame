// Purpose: Header file for menu.c
#ifndef MENU_H
#define MENU_H

#include "raylib.h"

// Define the game state
typedef enum GameState {
    GAME_RUNNING,
    GAME_PAUSED,
    GAME_MENU,
    GAME_EXIT,
    GAME_SETTINGS,
    GAME_MENU_ENTER
} GameState;

// Define the gamestate object
extern GameState gameState;

// allocate memory for the menu functions in menu.c
void DrawPauseMenu();
void DrawMainManu();
void DrawSettingsMenu();

#endif