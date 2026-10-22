#include "Game.h"
#include "GameManager.h"
#include "raylib.h"
#include "Button.h"
#include <ctime>
#include <cstdlib>

namespace Asteroids
{
	void RunGame()
	{
		srand(static_cast<unsigned int>(time(nullptr)));

		float delta = 0.0f;
		bool gameIsRunning = true;

		InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Party Starter!");

		Font font = LoadFontEx("res/Font/Super Wonder.ttf", 200, NULL, 0);
		Texture2D backgroundMenu = LoadTexture("res/Backgrounds/BackgroundMenu.png");
		Texture2D backgroundGameplay = LoadTexture("res/Backgrounds/BackgroundTwo_Gameplay.png");
		Texture2D canion = LoadTexture("res/Ship/Canion.png");
		Texture2D confetti = LoadTexture("res/Ship/Confetti.png");
		Texture2D playButton = LoadTexture("res/Buttons/YELLOW_BUTTON.png");
		Texture2D rulesButton = LoadTexture("res/Buttons/VIOLET_BUTTON.png");
		Texture2D creditsButton = LoadTexture("res/Buttons/GREEN_BUTTON.png");
		Texture2D exitButton = LoadTexture("res/Buttons/BLUE_BUTTON.png");
		Texture2D playPressedButton = LoadTexture("res/Buttons/YELLOW_BUTTON_PRESSED.png");
		Texture2D rulesPressedButton = LoadTexture("res/Buttons/VIOLET_BUTTON_PRESSED.png");
		Texture2D creditsPressedButton = LoadTexture("res/Buttons/GREEN_BUTTON_PRESSED.png");
		Texture2D exitPressedButton = LoadTexture("res/Buttons/BLUE_BUTTON_PRESSED.png");

		while (!WindowShouldClose() && gameIsRunning)
		{
			delta = GetFrameTime();
			Update(delta, gameIsRunning, canion);

			Draw(backgroundMenu, backgroundGameplay, canion, confetti, playButton, rulesButton, creditsButton, exitButton,
				playPressedButton, rulesPressedButton, creditsPressedButton, exitPressedButton, font);
		}

		UnloadTexture(backgroundMenu);

		CloseWindow();
	}
}