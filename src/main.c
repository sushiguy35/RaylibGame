#include "raylib.h"
#include "player.c"
#include <stdio.h>

#define SCREENHEIGHT 500
#define SCREENWIDTH 1000

int main()
{
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Game");
	SetTargetFPS(60);

	while(!WindowShouldClose())
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

		BeginDrawing();
			ClearBackground(RAYWHITE);
			// Draw Player
			DrawRectangle(player.x, player.y, player.width, player.height, RED);
		EndDrawing();
	}
	
	CloseWindow();
}
