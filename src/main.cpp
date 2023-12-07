// all includes
#include "raylib.h"
#include <stdio.h>
#include "player.c"
#include "headers/levels.h"
#include "headers/menu.cpp"

// define the screen height and width
#define SCREENHEIGHT 450
#define SCREENWIDTH 800

int level = 0;	// Define the level
int course = 0; // Define the course

double startTime;  // Save the start time
double elapsedTime;  // Calculate the elapsed time

Music music; // Define the music object
float tempMusicVolume = 0.5f; // Define the music volume


// Define the resetPlayer function
void resetPlayer()
{
    // reset the player to the start position
    player.x = 100;
    player.y = 215;
    player.width = 25;
    player.height = 25;
	player.speed = 2;
    player.lives = 3;
    // Define the player rectangle
    player.rec.x = 100;
    player.rec.y = 225;
    player.rec.width = 25;
    player.rec.height = 35;

	level = 1; // Reset the level
	course = 5; // Reset the course

	startTime = GetTime();  // Save the start time
}

// The main function
int main()
{
	// Initialize all properties for raylib
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Game");
	SetTargetFPS(60);
	SetExitKey(KEY_F4);

	InitAudioDevice(); // Initialize audio device

	Music music = LoadMusicStream("assets/music.wav");

	// Play the music
	PlayMusicStream(music);

	if (music.stream.buffer == NULL) 
	{
    	printf("Failed to load music\n");
    	return -1;
	}

	// define the time when the game starts
	startTime = GetTime();

	resetPlayer(); // Reset the player

	// Initialize the game to start in the menu
	gameState = GAME_MENU_ENTER;

	// Main game loop
	while(!WindowShouldClose() && run == true)
	{
		// Set Variables for the ingame timer
		double currentTime = GetTime();  // Get the current time
		double elapsedTime = currentTime - startTime;  // Calculate the elapsed time

		UpdateMusicStream(music); // Update the music stream

		if (gameState != PLAYER_DEAD)
		{
			SetMusicVolume(music, musicVolume * 3);
		} else 
		{
			SetMusicVolume(music, 0);
		}

		// Check if the escape key is pressed
		if (IsKeyPressed(KEY_ESCAPE)) 
		{
        	if (gameState == GAME_RUNNING)  // If the game is running
			{
           		gameState = GAME_PAUSED; // Pause the game

        	} 
			else if (gameState == GAME_PAUSED) // if the game is paused
			{
            	gameState = GAME_RUNNING; // Resume the game
        	}
    	}

		if (IsKeyPressed(KEY_ENTER))  // Check if the enter key is pressed
		{
    		if (gameState == GAME_PAUSED) // If the game is paused
    		{
        		gameState = GAME_MENU_ENTER; // Go back to the main menu
    		} 
		}

		if (gameState == GAME_MENU_ENTER) // If the game is in the main menu enter state
		{
			gameState = GAME_RUNNING; // Start the game
    		elapsedTime = 0.0; // Reset the timer
    		gameState = GAME_MENU; // Go to the main menu state
		}

		if (gameState == GAME_MENU) // If the game is in the main menu
		{
    		DrawMainManu(); // Draw the main menu
		}	

		if (gameState == GAME_SETTINGS) // If the game is in the settings menu
		{
			DrawSettingsMenu(); // Draw the settings menu
		}

		if (gameState == PLAYER_DEAD) // If the game is in the settings menu
		{
			DrawDeathScreen(); // Draw the settings menu
		}

		if (gameState == GAME_RUNNING) // If the game is running
		{ // Draw all the stuff for the game
		// Move Player
		if (IsKeyDown(KEY_RIGHT)) // Check if the right key is pressed
		{
			player.x += player.speed; // Move the player to the right
		} 
		if (IsKeyDown(KEY_LEFT)) // Check if the left key is pressed
		{
			player.x -= player.speed; // Move the player to the left
		}
		if (IsKeyDown(KEY_UP)) // Check if the up key is pressed
		{
			player.y -= player.speed; // Move the player up
		}
		if (IsKeyDown(KEY_DOWN)) // Check if the down key is pressed
		{
			player.y += player.speed; // Move the player down
		}
		if (IsKeyPressed(KEY_R)) // Check if the r key is pressed
		{
			resetPlayer(); // Reset the player
		}
		if (IsKeyDown(KEY_LEFT_SHIFT)) // Check if the left shift key is pressed
		{
			player.speed = 6; // Set the player speed to 4
		} else 
		{
			player.speed = 3; // Set the player speed to 2
		}
		
		// Start Drawing
		BeginDrawing();
			ClearBackground(RAYWHITE); // Clear the background with the color white
			if (level == 1 && course == 0) // If the level is 1 and the course is 0
			{
				DrawLevelZero(SCREENHEIGHT); // Draw the Starting level aka level zero
				
				if (player.x >= 800) // If the player is at the end of the level
				{
					player.x = 0; // Reset the player x position
					course = 2; // move to the next course
				}	
			} else if (course == 1 && level == 1) // If the course is 1 and the level is 1
			{
				DrawLevelOne(); // Draw the first level	

				if (player.x >= 800) // If the player is at the end of the level
				{
					player.x = 0; // Reset the player x position
					level = 1; // Reset the level
					course = 2; // Move to the next course
				}	
			} else if (course == 2 && level == 1) // If the course is 1 and the level is 2
			{
				DrawLevelTwo(); // Draw the second level

				if (player.x >= 800) // If the player is at the end of the level
				{
					player.x = 0; // Reset the player x position
					level = 1; // Reset the level
					course = 3; // Move to the next course
				}	
			} else if (course == 3 && level == 1) // If the course is 3 and the level is 1
			{
				DrawLevelThree(); // Draw the third level

				if (player.x >= 800) // If the player is at the end of the level
				{
					player.x = 0; // Reset the player x position
					level = 1; // Reset the level
					course = 4; // Move to the next course
				}	
			} else if (course == 4 && level == 1) // If the course is 3 and the level is 1
			{
				DrawLevelFour(); // Draw the fourth level

				if (player.x >= 800) // If the player is at the end of the level
				{
					player.x = 0; // Reset the player x position
					level = 1; // Reset the level
					course = 5; // Move to the next course
				}	
			} else if (course == 5 && level == 1) // If the course is 3 and the level is 1
			{
				DrawLevelFive(); // Draw the fourth level

				if (player.x >= 800) // If the player is at the end of the level
				{
					player.x = 0; // Reset the player x position
					level = 1; // Reset the level
					course = 6; // Move to the next course
				}	
			} 
			
			// Draw Player
			DrawRectangle(player.x, player.y, player.width, player.height, BLUE);

			// Draw UI
			DrawText(TextFormat("Level: %d.%d", level, course), 640, 30, 30, BLACK);

			DrawText(TextFormat("Time: %.1f", elapsedTime), SCREENWIDTH / 2 - MeasureText("lives: §", 30), 30, 30, BLACK); // Draw the timer

            DrawText(TextFormat("Lives: %d", player.lives), 35    , 30, 30, BLACK);

		} // End of game loop
		else if (gameState == GAME_PAUSED) // If the game is paused
		{ 
			DrawPauseMenu(); // Draw the pause menu
		}

		EndDrawing(); // End drawing
	} 
	if (WindowShouldClose())  // If the window should close
	{
    	gameState = GAME_EXIT; // Change the game state to exit
	}

	UnloadMusicStream(music);
    CloseAudioDevice(); // Close audio device

	CloseWindow(); // Close the window
}
