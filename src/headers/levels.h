#include "raylib.h"
#include <stdio.h>
#include "../player.c"
#include "enimie.c"


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
	if (player.y <= 25)
	{	
    	player.y = 25;
    	printf("Collided with top wall\n");
	} else if (player.y >= 400)
	{
		player.y = 400;
		printf("Collided with bottom wall\n");
	} else if (player.x <= 25 && player.y <= 175)
	{
		player.x = 25;
		printf("Collided with top left wall\n");
	} else if (player.x <= 25 && player.y >= 250)
	{
		player.x = 25;
		printf("Collided with bottom left wall\n");
	} else if (player.x >= 750 && player.y <= 175)
	{
		player.x = 750;
		printf("Collided with top right wall\n");
	} else if (player.x >= 750 && player.y >= 250)
	{
		player.x = 750;
		printf("Collided with bottom right wall\n");
	}
}


void DrawLevelZero(int screenheight)
{
	// Draw Help
	DrawText("Go In Here -->", 500, screenheight / 2 - 15, 30, GRAY);

	// Wall variables
	Rectangle topwall;
	topwall.x = 0;
	topwall.y = 0;
	topwall.width = 800;
	topwall.height = 25;

	// Draw Walls
	// top wall
	DrawRectangle(0, 0, 800, 25, GREEN);
    // left wall
	DrawRectangle(0, 0, 25, 450, GREEN);
	// bottom wall
	DrawRectangle(0, 425, 800, 25, GREEN);
	// top right wall
	DrawRectangle(775, 0, 25, 175, GREEN);
	// bottom right wall
	DrawRectangle(775, 275, 25, 175, GREEN);

	// Collsisions
	if (player.x <= 25)
	{
		player.x = 26;
		printf("Collided with left wall\n");
	} else if (player.y <= 25)
	{
		player.y = 25;
		printf("Collided with top wall\n");
	} else if (player.y >= 400)
	{
		player.y = 399;
		printf("Collided with bottom wall\n");
	} else if (player.x >= 750 && player.y <= 175)
	{
		player.x = 749;
		printf("Collided with top right wall\n");
	} else if (player.x >= 750 && player.y >= 250)
	{
		player.x = 749;
		printf("Collided with bottom right wall\n");
	}
	
}

void DrawLevelOne()
{
	DrawTemplate();
	
	CreateEnimie(0, 300, 100, 10); // For the first enemy
	CreateEnimie(1, 500, 300, 10); // For the second enemy
	

	// PLAYER DEATH
	Rectangle playerRec = {player.x, player.y, player.width, player.height};

	for (int i = 0; i < MAX_ENIMIES; i++) {
    	Rectangle enimRec = {enimies[i].x, enimies[i].y, 25, 25}; // Assuming the enemy is 25x25 pixels

    	if (CheckCollisionRecs(playerRec, enimRec)) {
        	died();
        	return;
    	}
	}
}

void DrawLevelTwo()
{
	DrawTemplate();
	
	CreateEnimie(1, 100, 100, 12); // For the first enemy
	CreateEnimie(2, 200, 200, 13); // For the second enemy
	CreateEnimie(3, 300, 300, 14); // For the Third enemy

	

	// PLAYER DEATH
	Rectangle playerRec = {player.x, player.y, player.width, player.height};

	for (int i = 0; i < MAX_ENIMIES; i++) {
    	Rectangle enimRec = {enimies[i].x, enimies[i].y, 25, 25}; // Assuming the enemy is 25x25 pixels

    	if (CheckCollisionRecs(playerRec, enimRec)) {
        	died();
        	return;
    	}
	}
}

void DrawLevelThree()
{
	DrawTemplate();
	
	CreateEnimie(0, 300, 100, 40); // For the first enemy
	CreateEnimie(1, 500, 300, 40); // For the second enemy

	// PLAYER DEATH
	Rectangle playerRec = {player.x, player.y, player.width, player.height};

	for (int i = 0; i < MAX_ENIMIES; i++) {
    	Rectangle enimRec = {enimies[i].x, enimies[i].y, 25, 25}; // Assuming the enemy is 25x25 pixels

    	if (CheckCollisionRecs(playerRec, enimRec)) {
        	died();
        	return;
    	}
	}

	DrawRectangle(100, 215, 25, 100, RED);

	if (CheckCollisionRecs(playerRec, (Rectangle){100, 215, 25, 100}))
	{
		died();
	}
}