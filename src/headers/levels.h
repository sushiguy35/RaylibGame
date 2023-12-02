// all the levels are here
// all include
#include "raylib.h"
#include <stdio.h>
#include "player.h"
#include "enimie.c"

// define the functio to draw a level template which is used in almost all levels
void DrawTemplate()
{
	// top left wall
	DrawRectangle(0, 0, 25, 175, GREEN);
	// bottom left wall
	DrawRectangle(0, 275, 25, 175, GREEN);
	// top wall
	DrawRectangle(0, 0, 800, 25, GREEN);
	// bottom right wall
	DrawRectangle(775, 275, 25, 175, GREEN);
	// Top right wall
	DrawRectangle(775, 0, 25, 175, GREEN);
	// bottom wall
	DrawRectangle(0, 425, 800, 25, GREEN);
	

	// Collisions
	if (player.y <= 25) // Top wall
	{	
    	player.y = 25;
    	printf("Collided with top wall\n");
	} else if (player.y >= 400) // Bottom wall
	{
		player.y = 400;
		printf("Collided with bottom wall\n");
	} else if (player.x <= 25 && player.y <= 175) // Top left wall
	{
		player.x = 25;
		printf("Collided with top left wall\n");
	} else if (player.x <= 25 && player.y >= 250) // Bottom left wall
	{
		player.x = 25;
		printf("Collided with bottom left wall\n");
	} else if (player.x >= 750 && player.y <= 175) // Top right wall
	{
		player.x = 750;
		printf("Collided with top right wall\n");
	} else if (player.x >= 750 && player.y >= 250) // Bottom right wall
	{
		player.x = 750;
		printf("Collided with bottom right wall\n");
	}
}

// Define the DrawLevelZero function
void DrawLevelZero(int screenheight)
{
	// Draw instructions on the map
	DrawText("Go In Here -->", 500, screenheight / 2 - 15, 30, GRAY);

	// Draw Walls
	
	DrawRectangle(0, 0, 800, 25, GREEN); 				// top wall
    
	DrawRectangle(0, 0, 25, 450, GREEN); 				// left wall
	
	DrawRectangle(0, 425, 800, 25, GREEN); 				// bottom wall

	DrawRectangle(775, 0, 25, 175, GREEN); 				// Top right wall
	
	DrawRectangle(775, 275, 25, 175, GREEN);		    // bottom right wall

	// Collsisions
	if (player.x <= 25) 								// Left wall
	{
		player.x = 25;
		printf("Collided with left wall\n");
	} else if (player.y <= 25) 							// Top wall
	{
		player.y = 25;
		printf("Collided with top wall\n");
	} else if (player.y >= 400) 						// Bottom wall
	{
		player.y = 400;
		printf("Collided with bottom wall\n");
	} else if (player.x >= 750 && player.y <= 175) 		// Top right wall
	{
		player.x = 750;
		printf("Collided with top right wall\n");
	} else if (player.x >= 750 && player.y >= 250) 		// Bottom right wall
	{
		player.x = 750;
		printf("Collided with bottom right wall\n");
	}
}

// Define the DrawLevelOne function
void DrawLevelOne()
{
	DrawTemplate(); // Draw the template for the level
	
	CreateEnimie(0, 300, 100, 10); // Draw the first enemy
	CreateEnimie(1, 500, 300, 10); // Draw the second enemy
	

	// PLAYER DEATH
	Rectangle playerRec = {player.x, player.y, player.width, player.height};  // Define the player rectangle variable

	for (int i = 0; i < MAX_ENIMIES; i++) {  								  // Loop through all enimies
    	Rectangle enimRec = {enimies[i].x, enimies[i].y, 25, 25};             // Define the enimie rectangle variable

    	if (CheckCollisionRecs(playerRec, enimRec)) { 					      // Check if the player rectangle is colliding with the enimie rectangle
        	died(); // kill the player
        	return;
    	}
	}
}


// Define the DrawLevelTwo function
void DrawLevelTwo()
{
	DrawTemplate(); // Draw the template for the level
	
	CreateEnimie(1, 100, 100, 12); // Draw the first enemy
	CreateEnimie(2, 200, 200, 13); // Draw the second enemy
	CreateEnimie(3, 300, 300, 14); // Draw the Third enemy

	

	// PLAYER DEATH
	Rectangle playerRec = {player.x, player.y, player.width, player.height}; // Define the player rectangle variable

	for (int i = 0; i < MAX_ENIMIES; i++) {  // Loop through all enimies
    	Rectangle enimRec = {enimies[i].x, enimies[i].y, 25, 25}; // Define the enimie rectangle variable

    	if (CheckCollisionRecs(playerRec, enimRec)) { // Check if the player rectangle is colliding with the enimie rectangle
        	died(); // kill the player
        	return;
    	}
	}
}


// Define the DrawLevelThree function
void DrawLevelThree()
{
	DrawTemplate(); // Draw the template for the level
	
	CreateEnimie(0, 300, 100, 40); // Draw the first enemy
	CreateEnimie(1, 500, 300, 40); // Draw the second enemy

	// PLAYER DEATH
	Rectangle playerRec = {player.x, player.y, player.width, player.height}; // Define the player rectangle variable

	for (int i = 0; i < MAX_ENIMIES; i++) { // Loop through all enimies
    	Rectangle enimRec = {enimies[i].x, enimies[i].y, 25, 25}; // define the enimie rectangle variable

    	if (CheckCollisionRecs(playerRec, enimRec)) { // Check if the player rectangle is colliding with the enimie rectangle
        	died(); // kill the player
        	return;
    	}
	}

	DrawRectangle(100, 215, 25, 100, RED); // Draw A Deadly Red Rectangle

	if (CheckCollisionRecs(playerRec, (Rectangle){100, 215, 25, 100})) // Check if the player rectangle is colliding with the deadly red rectangle
	{
		died(); // kill the player
	}
}