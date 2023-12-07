// all the levels are here
// all include
#include "raylib.h"
#include <stdio.h>
#include "player.h"
#include "enimie.c"
#include <stdlib.h>
#include <time.h>
#include<math.h>

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
        	if (player.lives <= 1)
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
	SetTargetFPS(60);
    static bool showText = true;


    DrawTemplate();

    if (showText)
	{
    	DrawRectangle(0, 0, 800, 450, BLACK);
    	int screenWidth = GetScreenWidth();
    	int screenHeight = GetScreenHeight();
    	const char* text = "Boss Fight";
    	int fontSize = 60;
    	Vector2 textSize = MeasureTextEx(GetFontDefault(), text, fontSize, 0);
    	float textX = screenWidth/2 - textSize.x/2;
    	float textY = screenHeight/2 - textSize.y/2;

    	DrawText(text, textX, textY, fontSize, RED);
		DrawText("Press Space To Start", 250, 300, 30, WHITE);

		static int counter = 0;
		counter++;
		printf("%d\n", counter);

		printf("FPS: %d\n", GetFPS());

    	player.width = 0;
		DrawFPS(10, 10);

    	if (IsKeyDown(KEY_SPACE))
		{
    		showText = false;
			printf("Space was pressed\n");
		}
		else
		{
    		showText = true; // Reset the showText variable
		}

	}
    else if (!showText)
    {
		static int count = 0;

		if (count == 0)
		{
			player.width = 25;
			player.height = 25;
			player.x = 0;
			player.y = 215;
			player.lives = 3;
			count++;
		}

        DrawTemplate();

        typedef struct Boss {
            Rectangle rec;
            Texture2D image;
            int x;
            int y;
            float speed;
            bool dead;
        } Boss;

        Boss boss;

        boss.x = 400;
        boss.y = 200;
        boss.speed = 2.0f;  // Set the boss's speed

        boss.image = LoadTexture("assets/boss.png");
        DrawTexture(boss.image, boss.x, boss.y, WHITE);

        boss.rec = (Rectangle){boss.x, boss.y, 200, 160};

        Rectangle playerRec = {player.x, player.y, player.width, player.height}; // Define the player rectangle variable

        // Draw the boss
        DrawTexture(boss.image, boss.x, boss.y, WHITE);

        if (CheckCollisionRecs(playerRec, boss.rec))
        {   
            printf("Collided with boss\n");

            if (player.lives <= 1)
            {
                died();
            } 
            else
            {
                player.x = 30;
                player.y = 215;
                player.lives--;
            }
            return;
        }

		// Move the boss
		boss.y += boss.speed;
		if (boss.y >= 400) // If the boss is at the bottom of the screen
		{
			boss.speed = -2.0f; // Start moving up
		}
		else if (boss.y <= 25) // If the boss is at the top of the screen
		{
			boss.speed = 2.0f; // Start moving down
		}

        // Spawn enemies on each side of the boss
        CreateEnimie(1, 50, 50, 10); // Enemy on the right
		CreateEnimie(2, 75, 50, 10); // Enemy on the left
		CreateEnimie(3, 100, 50, 10); // Enemy on the right
		CreateEnimie(4, 125, 50, 10); // Enemy on the left
		CreateEnimie(5, 150, 50, 10); // Enemy on the right
		CreateEnimie(6, 175, 50, 10); // Enemy on the left

		CreateEnimie(7, 250, 50, 10); // Enemy on the right
		CreateEnimie(8, 275, 50, 10); // Enemy on the left
		CreateEnimie(9, 300, 50, 10); // Enemy on the right
		CreateEnimie(10, 325, 50, 10); // Enemy on the left
		CreateEnimie(11, 350, 50, 10); // Enemy on the right
		CreateEnimie(12, 375, 50, 10); // Enemy on the left

		CreateEnimie(13, 500, 50, 10); // Enemy on the right
		CreateEnimie(14, 525, 50, 10); // Enemy on the left
		CreateEnimie(15, 550, 50, 10); // Enemy on the right
		CreateEnimie(16, 575, 50, 10); // Enemy on the left
		CreateEnimie(17, 600, 50, 10); // Enemy on the right
		CreateEnimie(18, 625, 50, 10); // Enemy on the left

		for (int i = 0; i < MAX_ENIMIES; i++) 
		{ // Loop through all enimies
    		Rectangle enimRec = {enimies[i].x, enimies[i].y, 25, 25}; // define the enimie rectangle variable

    		if (CheckCollisionRecs(playerRec, enimRec)) 
			{ // Check if the player rectangle is colliding with the enimie rectangle
        		if (player.lives <= 0)
            	{
                	died();
            	} else
            	{
                	player.x = 0;
                	player.y = 215;
                	player.lives--;
            	}
    		}
		}
    }
}