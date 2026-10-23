#include "ScreenPause.h"
#include "ScreenPlay.h"
#include "GameManager.h"
#include "Button.h"
#include "raylib.h"

namespace Asteroids
{
	Pause pauseText;
	Pause continueButton;
	Pause menuButton;

	void PauseInit()
	{
		pauseText.text.x = 400;
		pauseText.text.y = 200;
		pauseText.fontSize = 100;
		pauseText.spacing = 2;

		continueButton.position.x = 380;
		continueButton.position.y = 320;
		continueButton.size.y = 80;
		continueButton.size.x = 280;
		continueButton.text.x = 420;
		continueButton.text.y = 338;
		continueButton.fontSize = 50;
		continueButton.spacing = 2;

		menuButton.position.x = 380;
		menuButton.position.y = 460;
		menuButton.size.y = 80;
		menuButton.size.x = 280;
		menuButton.text.x = 415;
		menuButton.text.y = 490;
		menuButton.fontSize = 35;
		menuButton.spacing = 2;
	}

	void PauseDraw(Texture2D backgroundGameplay, Texture2D canion, Texture2D confetti,
		Texture2D piniataOne, Texture2D piniataTwo, Texture2D piniataThree, Font font,
		Texture2D pauseButtonScreen, Texture2D pauseButtonScreenPressed)
	{
		Vector2 mousePosition = GetMousePosition();

		GameplayDraw(backgroundGameplay, canion, confetti,
			piniataOne, piniataTwo, piniataThree, font);

		DrawTextEx(font, "PAUSE", pauseText.text, pauseText.fontSize, pauseText.spacing, WHITE);

#ifdef _DEBUG
		DrawRectangleV(continueButton.position, continueButton.size, VIOLET);
		DrawRectangleV(menuButton.position, menuButton.size, VIOLET);
#endif
		DrawTextureEx(pauseButtonScreen, continueButton.position, 0, 1, WHITE);
		DrawTextureEx(pauseButtonScreen, menuButton.position, 0, 1, WHITE);


		if (CheckCollisionMouseButton(mousePosition, continueButton.position.x, continueButton.position.y, continueButton.size.y, continueButton.size.x))
		{
#ifdef _DEBUG
			DrawRectangleV(continueButton.position, continueButton.size, BLUE);
#endif
			DrawTextureEx(pauseButtonScreenPressed, continueButton.position, 0, 1, WHITE);
		}
		else if (CheckCollisionMouseButton(mousePosition, menuButton.position.x, menuButton.position.y, menuButton.size.y, menuButton.size.x))
		{
#ifdef _DEBUG
			DrawRectangleV(menuButton.position, menuButton.size, BLUE);
#endif
			DrawTextureEx(pauseButtonScreenPressed, menuButton.position, 0, 1, WHITE);
		}

		DrawTextEx(font, "CONTINUE", continueButton.text, continueButton.fontSize, continueButton.spacing, WHITE);
		DrawTextEx(font, "BACK TO MENU", menuButton.text, menuButton.fontSize, menuButton.spacing, WHITE);
	}

	void PauseUpdate(Sound menuButtonsSound)
	{
		Vector2 mousePosition = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (CheckCollisionMouseButton(mousePosition, continueButton.position.x, continueButton.position.y, 
				continueButton.size.y, continueButton.size.x))
			{
				currentScreen = Screen::Play;

				if (!IsSoundPlaying(menuButtonsSound))
				{
					PlaySound(menuButtonsSound);
				}
			}
			else if (CheckCollisionMouseButton(mousePosition, menuButton.position.x, menuButton.position.y,
				menuButton.size.y, menuButton.size.x))
			{
				currentScreen = Screen::Menu;

				if (!IsSoundPlaying(menuButtonsSound))
				{
					PlaySound(menuButtonsSound);
				}
			}
		}
	}


}