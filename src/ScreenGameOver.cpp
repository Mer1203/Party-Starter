#include "ScreenGameOver.h"
#include "ScreenPlay.h"
#include "Asteroids.h"
#include "Player.h"
#include "Button.h"
#include "raylib.h"

namespace Asteroids
{
	GameOver gameOverTExt;
	GameOver retryButton;
	GameOver menuButtonGO;

	void GameOverInit()
	{
		gameOverTExt.text.x = 300;
		gameOverTExt.text.y = 200;
		gameOverTExt.fontSize = 100;
		gameOverTExt.spacing = 2;

		retryButton.position.x = 380;
		retryButton.position.y = 320;
		retryButton.size.y = 80;
		retryButton.size.x = 280;
		retryButton.text.x = 460;
		retryButton.text.y = 338;
		retryButton.fontSize = 50;
		retryButton.spacing = 2;

		menuButtonGO.position.x = 380;
		menuButtonGO.position.y = 460;
		menuButtonGO.size.y = 80;
		menuButtonGO.size.x = 280;
		menuButtonGO.text.x = 415;
		menuButtonGO.text.y = 490;
		menuButtonGO.fontSize = 35;
		menuButtonGO.spacing = 2;
	}

	void GameOverUpdate(Texture2D canion)
	{
		Vector2 mousePosition = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (CheckCollisionMouseButton(mousePosition, retryButton.position.x, retryButton.position.y,
				retryButton.size.y, retryButton.size.x))
			{
				GameplayInit();
				PlayerInit(canion);
				AsteroidsInitAll();
				for (int i = 0; i < MAX_BULLETS; i++)
				{
					BulletsInit(bullets[i]);
				}

				currentScreen = Screen::Play;
			}
			else if (CheckCollisionMouseButton(mousePosition, menuButtonGO.position.x, menuButtonGO.position.y,
				menuButtonGO.size.y, menuButtonGO.size.x))
			{
				currentScreen = Screen::Menu;
			}
		}
	}

	void GameOverDraw(Texture2D backgroundGameplay, Texture2D canion, Texture2D confetti,
		Texture2D piniataOne, Texture2D piniataTwo, Texture2D piniataThree, Font font,
		Texture2D pauseButtonScreen, Texture2D pauseButtonScreenPressed)
	{
		Vector2 mousePosition = GetMousePosition();

		GameplayDraw(backgroundGameplay, canion, confetti,
			piniataOne, piniataTwo, piniataThree, font);

		DrawTextEx(font, "GAME OVER!", gameOverTExt.text, gameOverTExt.fontSize, gameOverTExt.spacing, WHITE);

#ifdef _DEBUG
		DrawRectangleV(retryButton.position, retryButton.size, VIOLET);
		DrawRectangleV(menuButtonGO.position, menuButtonGO.size, VIOLET);
#endif
		DrawTextureEx(pauseButtonScreen, retryButton.position, 0, 1, WHITE);
		DrawTextureEx(pauseButtonScreen, menuButtonGO.position, 0, 1, WHITE);


		if (CheckCollisionMouseButton(mousePosition, retryButton.position.x, retryButton.position.y, retryButton.size.y, retryButton.size.x))
		{
#ifdef _DEBUG
			DrawRectangleV(retryButton.position, retryButton.size, BLUE);
#endif
			DrawTextureEx(pauseButtonScreenPressed, retryButton.position, 0, 1, WHITE);
		}
		else if (CheckCollisionMouseButton(mousePosition, menuButtonGO.position.x, menuButtonGO.position.y, menuButtonGO.size.y, menuButtonGO.size.x))
		{
#ifdef _DEBUG
			DrawRectangleV(menuButtonGO.position, menuButtonGO.size, BLUE);
#endif
			DrawTextureEx(pauseButtonScreenPressed, menuButtonGO.position, 0, 1, WHITE);
		}

		DrawTextEx(font, "RETRY", retryButton.text, retryButton.fontSize, retryButton.spacing, WHITE);
		DrawTextEx(font, "BACK TO MENU", menuButtonGO.text, menuButtonGO.fontSize, menuButtonGO.spacing, WHITE);
	}
}