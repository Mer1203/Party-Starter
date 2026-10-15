#include "Game.h"
#include "raylib.h"

void Game()
{
	const int WINDOW_WIDTH = 1024;
	const int WINDOW_HEIGHT = 768;

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Party Starter!");

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(WHITE); // system("cls");

		EndDrawing();
	}

	CloseWindow();

}
