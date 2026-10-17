#include "Game.h"
#include "GameManager.h"
#include "raylib.h"
#include "Button.h"

void Game()
{
	float delta = 0.0f;


	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Party Starter!");

	while (!WindowShouldClose())
	{
		delta = GetFrameTime();
		Update(delta);

		Draw();

	
	}

	CloseWindow();
}
