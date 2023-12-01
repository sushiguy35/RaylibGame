#include "raylib.h"
#include <stdio.h>
#include "headers/player.h"
#include "headers/levels.h"
#include "headers/shooting.h"


#define SCREENHEIGHT 450
#define SCREENWIDTH 800

unsigned int level = 0;

int main()
{
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Game");
	SetTargetFPS(60);

	player.x = 100;
	player.y = 100;
	player.width = 25;
	player.height = 25;

	player.rec.x = 100;
	player.rec.y = 225;
	player.rec.width = 25;
	player.rec.height = 35;

	while(!WindowShouldClose() && run == true)
	{
		// Move Player
		if (IsKeyDown(KEY_RIGHT))
		{
			player.x += 2;
		} 
		if (IsKeyDown(KEY_LEFT))
		{
			player.x -= 2;
		}
		if (IsKeyDown(KEY_UP))
		{
			player.y -= 2;
		}
		if (IsKeyDown(KEY_DOWN))
		{
			player.y += 2;
		}
		if (IsKeyDown(KEY_SPACE))
		{
			shoot();
		}

		BeginDrawing();
			ClearBackground(RAYWHITE);
			if (level == 0)
			{
				DrawLevelZero(SCREENHEIGHT);
				
				if (player.x >= 800)
				{
					printf("NEW LEVEL\n");
					player.x = 0;
					level = 1;
				}	
			} else if (level == 1)
			{
				DrawLevelOne();
				
			}
			

			Texture2D playerIdle = LoadTexture("./assets/player/idle.png");

			// Draw Player
			DrawTexture(playerIdle, player.x, player.y, WHITE);

			

		EndDrawing();
	}
	
	CloseWindow();
}
