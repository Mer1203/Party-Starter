#include "Game.h"
#include "GameManager.h"
#include "raylib.h"
#include "Button.h"

void Game()
{
	float delta = 0.0f;
	bool gameIsRunning = true;

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Party Starter!");

	while (!WindowShouldClose() && gameIsRunning)
	{
		delta = GetFrameTime();
		Update(delta, gameIsRunning);

		Draw();
	}

	CloseWindow();
}