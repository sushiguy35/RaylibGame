#include "raylib.h"
#include <stdio.h>
#include "headers/player.h"
#include "headers/levels.h"
#include "headers/shooting.h"


#define SCREENHEIGHT 450
#define SCREENWIDTH 800

int level = 1;
int course = 0;

int main()
{
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Game");
	SetTargetFPS(60);

	player.x = 796;
	player.y = 215;
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
			if (level == 1 && course == 0)
			{
				DrawLevelZero(SCREENHEIGHT);
				
				if (player.x >= 800)
				{
					player.x = 0;
					course = 1;
				}	
			} else if (course == 1 && level == 1)
			{
				DrawLevelOne();

				if (player.x >= 800)
				{
					player.x = 0;
					level = 1;
					course = 2;
				}	
			} else if (course == 2 && level == 1)
			{
				DrawLevelTwo();

				if (player.x >= 800)
				{
					player.x = 0;
					level = 1;
					course = 3;
				}	
			} else if (course == 3 && level == 1)
			{
				DrawLevelThree();

				if (player.x >= 800)
				{
					player.x = 0;
					level = 1;
					course = 4;
				}	
			}
			
			// Draw Player
			DrawRectangle(player.x, player.y, player.width, player.height, BLUE);

			// Draw UI
			DrawText(TextFormat("Level: %d.%d", level, course), 640, 30, 30, BLACK);
			

		EndDrawing();
	}
	
	CloseWindow();
}
