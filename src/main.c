#include "raylib.h"

int px, py;
int pw, ph;
int wh, ww;
int ps;

int main(int argc, char** argv)
{
	wh = 512;
	ww = 1024;

	ps = 1;

	pw = 25;
	ph = 50;

	InitWindow(ww, wh, "GAME!!");

	while (!WindowShouldClose())
	{
		// Input
		if (IsKeyDown(KEY_RIGHT)) { px += 1;  }
		if (IsKeyDown(KEY_LEFT))  { px -= 1; }
	
		// Draw
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawRectangle(px, py, pw, ph, RED);
		EndDrawing();

	}
}
