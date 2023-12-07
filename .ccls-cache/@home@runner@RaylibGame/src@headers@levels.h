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
        	if (player.lives <= 0)
            {
                died();
            } else
            {
                player.x = 30;
                player.y = 215;
                player.lives++;
            }
        	return;
    	}
	}
}


// Define the DrawLevelTwo function
void DrawLevelTwo()
{
	DrawTemplate(); // Draw the template for the level
	
	CreateEnimie(1, 100, 100, 10); // Draw the first enemy
	CreateEnimie(2, 200, 200, 10); // Draw the second enemy
	CreateEnimie(3, 300, 300, 10); // Draw the Third enemy

	

	// PLAYER DEATH
	Rectangle playerRec = {player.x, player.y, player.width, player.height}; // Define the player rectangle variable

	for (int i = 0; i < MAX_ENIMIES; i++) {  // Loop through all enimies
    	Rectangle enimRec = {enimies[i].x, enimies[i].y, 25, 25}; // Define the enimie rectangle variable

    	if (CheckCollisionRecs(playerRec, enimRec)) { // Check if the player rectangle is colliding with the enimie rectangle
        	if (player.lives <= 1)
            {
                player.x = 30;
                died();
            } else
            {
                player.x = 30;
                player.y = 215;
                player.lives--;
            }
        	return;
    	}
	}
}


// Define the DrawLevelThree function
void DrawLevelThree()
{
	DrawTemplate(); // Draw the template for the level
	
	CreateEnimie(0, 300, 100, 14); // Draw the first enemy
	CreateEnimie(1, 500, 300, 14); // Draw the second enemy

    
	Rectangle playerRec = {player.x, player.y, player.width, player.height}; // Define the player rectangle variable

	for (int i = 0; i < MAX_ENIMIES; i++) { // Loop through all enimies
    	Rectangle enimRec = {enimies[i].x, enimies[i].y, 25, 25}; // define the enimie rectangle variable

    	if (CheckCollisionRecs(playerRec, enimRec)) { // Check if the player rectangle is colliding with the enimie rectangle
        	if (player.lives <= 1)
            {
                died();
            } else
            {
                player.x = 30;
                player.y = 215;
                player.lives--;
            }
        	return;
    	}
	}

	DrawRectangle(100, 215, 25, 100, RED); // Draw A Deadly Red Rectangle

	if (CheckCollisionRecs(playerRec, (Rectangle){100, 215, 25, 100})) // Check if the player rectangle is colliding with the deadly red rectangle
	{
		if (player.lives <= 1)
            {
                died();
            } else
            {
                player.x = 30;
                player.lives--;
            }
	}
}


void DrawLevelFour()
{
    int speed = 5; // the speed of the enemy's movement
    DrawTemplate(); // Draw the template for the level

    CreateEnimie(1, 100, 25, 10);
    CreateEnimie(2, 125, 25, 10);
    CreateEnimie(3, 150, 50, 10);
    CreateEnimie(4, 175, 50, 10);
    CreateEnimie(5, 200, 75, 10);
    CreateEnimie(6, 225, 75, 10);
    CreateEnimie(7, 250, 100, 10);
    CreateEnimie(8, 275, 100, 10);
    CreateEnimie(9, 300, 125, 10);
    CreateEnimie(10, 325, 125, 10);
    CreateEnimie(11, 350, 150, 10);
    CreateEnimie(12, 375, 150, 10);
    CreateEnimie(13, 400, 175, 10);
    CreateEnimie(14, 425, 175, 10);
    CreateEnimie(15, 450, 200, 10);
    CreateEnimie(16, 475, 200, 10);
    CreateEnimie(17, 500, 225, 10);
    CreateEnimie(18, 525, 225, 10);
    CreateEnimie(19, 550, 250, 10);
    CreateEnimie(20, 575, 250, 10);
    CreateEnimie(21, 600, 275, 10);
    CreateEnimie(21, 600, 275, 10);
    
	Rectangle playerRec = {player.x, player.y, player.width, player.height}; // Define the player rectangle variable
    
    
    for (int i = 0; i < MAX_ENIMIES; i++) { // Loop through all enimies
    	Rectangle enimRec = {enimies[i].x, enimies[i].y, 25, 25}; // define the enimie rectangle variable

    	if (CheckCollisionRecs(playerRec, enimRec)) { // Check if the player rectangle is colliding with the enimie rectangle
        	if (player.lives <= 1)
            {
                died();
            } else
            {
                player.x = 30;
                player.y = 215;
                player.lives--;
            }
        	return;
    	}
	}
}


void DrawLevelFive()
{
    
}