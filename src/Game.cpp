#include "Game.h"
#include "GameManager.h"
#include "raylib.h"
#include "Button.h"
#include <ctime>
#include <cstdlib>

void Game()
{
	float delta = 0.0f;
	bool gameIsRunning = true;

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Party Starter!");
	
	Font font = LoadFont("res/Font/Super Wonder.ttf");
	Texture2D backgroundMenu = LoadTexture("res/Backgrounds/BackgroundMenu.png");
	Texture2D backgroundGameplay = LoadTexture("res/Backgrounds/BackgroundTwo_Gameplay.png");


	while (!WindowShouldClose() && gameIsRunning)
	{
		delta = GetFrameTime();
		Update(delta, gameIsRunning);

		Draw(backgroundMenu, backgroundGameplay);
	}

	UnloadTexture(backgroundMenu);

	CloseWindow();
}