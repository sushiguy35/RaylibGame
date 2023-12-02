/*
   This file is meant to handle all the menu related functions
*/

#define RAYGUI_IMPLEMENTATION // Define the implementation of raygui or else it wont work

// all the includes
#include "menu.h"
#include "raylib.h"
#include "raygui.h"
#include "player.h"

// Define the game state
GameState gameState = GAME_RUNNING;

// Define the volume variable
float volume = 0.5f; // Initialize volume to 50%

// Define the DrawButton function which is made to make buttons
bool DrawButton(int x, int y, int width, int height, char* text)
{
    Rectangle button = { x, y, width, height };

    // Measure the text
    int textWidth = MeasureText(text, 20);
    int textX = x + width / 2 - textWidth / 2;
    int textY = y + height / 2 - 10; // 10 is half the font size

    // Draw the button
    DrawRectangleRec(button, RED);
    DrawText(text, textX, textY, 20, WHITE);

    // Check if the mouse pointer is over the button
    Vector2 mousePoint = GetMousePosition();
    if (CheckCollisionPointRec(mousePoint, button))
    {
        // Change the button color to indicate it's being hovered over
        DrawRectangleRec(button, GREEN);
        DrawText(text, textX, textY, 20, WHITE);

        // Check if the left mouse button is pressed
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            return true;
        }
    }

    return false;
}


// The setting menu function
void DrawSettingsMenu()
{
    // Draw background and title
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.5f));
    DrawText("Settings", GetScreenWidth() / 2 - MeasureText("Settings", 40) / 2, 50, 40, GRAY);

    // define the tempvolume pointer which is necessary for the GuiSliderBar function
    float *tempvolume = &volume;

    // Draw the volume settings
    DrawText("Volume", GetScreenWidth() / 2 - MeasureText("Volume", 20) / 2, 150, 25, GRAY);

    // Define the text which is used for displaying the volume
    char volumeText[32];
    sprintf(volumeText, "%d%%", (int)(*tempvolume * 100));

    // Change the font size to 17 for the slider
    int defaultSize = GuiGetStyle(DEFAULT, TEXT_SIZE);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 17); 

    // Draw the main audio slider
    GuiSliderBar((Rectangle){ GetScreenWidth() / 2 - 170 / 2, 200, 170, 30 }, "Main", volumeText, tempvolume, 0.0f, 1.0f);

    GuiSetStyle(DEFAULT, TEXT_SIZE, defaultSize); // Reset the font size to the default size

    // Check if the ESC key is pressed
    if (IsKeyPressed(KEY_ESCAPE)) {
        gameState = GAME_MENU; // Change the game state to the main menu and return
        return;
    }

}

// The main menu function
void DrawMainManu()
{
    // Draw the background and the title
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLUE, 0.5f));
    DrawText("RaylibGame", GetScreenWidth() / 2 - MeasureText("RaylibGame", 40) / 2, GetScreenHeight() / 2 - 200, 40, BLACK);
    
    // Draw the buttons and check if they are pressed and then change the game state accordingly
    if (DrawButton(GetScreenWidth() / 2 - 50, 150, 100, 50, "Play"))
    {
        gameState = GAME_RUNNING;
        resetPlayer();
    }   
    if (DrawButton(GetScreenWidth() / 2 - 50, 250, 100, 50, "Settings"))
    {
        gameState = GAME_SETTINGS;
    }
    if (DrawButton(GetScreenWidth() / 2 - 50, 350, 100, 50, "Exit"))
    {
        CloseWindow();
    }
}

// The pause menu function
void DrawPauseMenu() {
    // Draw the background and the title
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.5f));
    DrawText("Game Paused", GetScreenWidth() / 2 - MeasureText("Game Paused", 20) / 2, GetScreenHeight() / 2 - 150, 20, GRAY);

    // Draw the text to instruct the user on how to resume, return to menu or exit
    DrawText("Press [ESC] to resume", GetScreenWidth() / 2 - MeasureText("Press [ESC] to resume", 20) / 2, GetScreenHeight() / 2 - 50, 20, LIGHTGRAY);
    DrawText("Press [ENTER] to return to menu", GetScreenWidth() / 2 - MeasureText("Press [ENTER] to return to menu", 20) / 2, GetScreenHeight() / 2, 20, LIGHTGRAY);
    DrawText("Press [SPACE] to exit", GetScreenWidth() / 2 - MeasureText("Press [SPACE] to exit", 20) / 2, GetScreenHeight() / 2 + 50, 20, LIGHTGRAY);

    // heck if any of the keys are pressed and change the game state accordingly
    if (IsKeyPressed(KEY_ENTER)) {
        gameState = GAME_MENU;
        return;
    } else if (IsKeyPressed(KEY_SPACE)) {
        CloseWindow();
        return;
    }
}