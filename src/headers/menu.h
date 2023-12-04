// Purpose: Header file for menu.cpp
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
    GAME_MENU_ENTER,
    PLAYER_DEAD
} GameState;

// Define the gamestate object
extern GameState gameState;

// allocate memory for the menu functions in menu.cpp
void DrawPauseMenu();
void DrawMainManu();
void DrawSettingsMenu();
void DrawDeathScreen();

#endif