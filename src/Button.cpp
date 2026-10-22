#include "Button.h"
#include "raylib.h"

namespace Asteroids
{
	Button play;
	Button rules;
	Button credits;
	Button exitGame;
	Button back;

	void ButtonInit()
	{
		play.isPressed = false;
		play.position.x = 700;
		play.position.y = 180;
		play.textPosition.x = 780;
		play.textPosition.y = 197;
		play.textSize = 40;
		play.size.y = 80; //height
		play.size.x = 280; //width
		play.fontSize = 60;
		play.spacing = 2;

		rules.isPressed = false;
		rules.position.x = 700;
		rules.position.y = 310;
		rules.textPosition.x = 775;
		rules.textPosition.y = 327;
		rules.textSize = 40;
		rules.size.y = 80;
		rules.size.x = 280;
		rules.fontSize = 60;
		rules.spacing = 2;

		credits.isPressed = false;
		credits.position.x = 700;
		credits.position.y = 440;
		credits.textPosition.x = 755;
		credits.textPosition.y = 456;
		credits.textSize = 40;
		credits.size.y = 80;
		credits.size.x = 280;
		credits.fontSize = 60;
		credits.spacing = 2;

		exitGame.isPressed = false;
		exitGame.position.x = 700;
		exitGame.position.y = 570;
		exitGame.textPosition.x = 800;
		exitGame.textPosition.y = 587;
		exitGame.textSize = 40;
		exitGame.size.y = 80;
		exitGame.size.x = 280;
		exitGame.fontSize = 60;
		exitGame.spacing = 2;

		back.position.x = 0;
		back.position.y = 0;
		back.size.y = 70;
		back.size.x = 70;
		back.textPosition.x = - 40;
		back.textPosition.y = - 20;
		back.textSize = 20;
		back.fontSize = 30;
		back.spacing = 2;
	}

	bool CheckCollisionMouseButton(Vector2 mousePosition, float buttonX, float buttonY, float buttonHeight, float buttonWidth)
	{
		return buttonX <= mousePosition.x && buttonX + buttonWidth >= mousePosition.x
			&& mousePosition.y >= buttonY && mousePosition.y <= buttonY + buttonHeight;
	}

	void IsMousePressed()
	{
		Vector2 mousePosition = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (CheckCollisionMouseButton(mousePosition, play.position.x, play.position.y, play.size.y, play.size.x))
			{
				currentScreen = Screen::Play;
			}
			else if (CheckCollisionMouseButton(mousePosition, rules.position.x, rules.position.y, rules.size.y, rules.size.x))
			{
				currentScreen = Screen::Rules;
			}
			else if (CheckCollisionMouseButton(mousePosition, credits.position.x, credits.position.y, credits.size.y, credits.size.x))
			{
				currentScreen = Screen::Credits;
			}
			else if (CheckCollisionMouseButton(mousePosition, exitGame.position.x, exitGame.position.y, exitGame.size.y, exitGame.size.x))
			{
				currentScreen = Screen::Exit;
			}
		}
	}

	void IsMousePressingBackButton()
	{
		Vector2 mousePosition = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (CheckCollisionMouseButton(mousePosition, back.position.x, back.position.y, back.size.y, back.size.x))
			{
				currentScreen = Screen::Menu;
			}
		}
	}

	void ButtonDraw(Vector2 mousePosition, Texture2D playButton, Texture2D rulesButton, Texture2D creditsButton,
		Texture2D exitButton, Texture2D playPressedButton, Texture2D rulesPressedButton, Texture2D creditsPressedButton,
		Texture2D exitPressedButton)
	{
		//DIBUJO BOTONES
#ifdef _DEBUG
		DrawRectangleV(play.position, play.size, VIOLET);
		DrawRectangleV(rules.position, rules.size, VIOLET);
		DrawRectangleV(credits.position, credits.size, VIOLET);
		DrawRectangleV(exitGame.position, exitGame.size, VIOLET);
#endif

		DrawTextureEx(playButton, play.position, 0, 1, WHITE);
		DrawTextureEx(rulesButton, rules.position, 0, 1, WHITE);
		DrawTextureEx(creditsButton, credits.position, 0, 1, WHITE);
		DrawTextureEx(exitButton, exitGame.position, 0, 1, WHITE);


		if (CheckCollisionMouseButton(mousePosition, play.position.x, play.position.y, play.size.y, play.size.x))
		{
#ifdef _DEBUG
			DrawRectangleV(play.position, play.size, BLUE);
#endif
			DrawTextureEx(playPressedButton, play.position, 0, 1, WHITE);
		}
		else if (CheckCollisionMouseButton(mousePosition, rules.position.x, rules.position.y, rules.size.y, rules.size.x))
		{
#ifdef _DEBUG
			DrawRectangleV(rules.position, rules.size, BLUE);
#endif
			DrawTextureEx(rulesPressedButton, rules.position, 0, 1, WHITE);
		}
		else if (CheckCollisionMouseButton(mousePosition, credits.position.x, credits.position.y, credits.size.y, credits.size.x))
		{
#ifdef _DEBUG
			DrawRectangleV(credits.position, credits.size, BLUE);
#endif
			DrawTextureEx(creditsPressedButton, credits.position, 0, 1, WHITE);
		}
		else if (CheckCollisionMouseButton(mousePosition, exitGame.position.x, exitGame.position.y, exitGame.size.y, exitGame.size.x))
		{
#ifdef _DEBUG
			DrawRectangleV(exitGame.position, exitGame.size, BLUE);
#endif
			DrawTextureEx(exitPressedButton, exitGame.position, 0, 1, WHITE);
		}
	}

	void ButtonTextDraw(Font font)
	{
		DrawTextEx(font, "PLAY", play.textPosition, play.fontSize, play.spacing, WHITE);
		DrawTextEx(font, "RULES", rules.textPosition, rules.fontSize, rules.spacing, WHITE);
		DrawTextEx(font, "CREDITS", credits.textPosition, credits.fontSize, credits.spacing, WHITE);
		DrawTextEx(font, "EXIT", exitGame.textPosition, exitGame.fontSize, exitGame.spacing, WHITE);
	}

	void BackButton(Texture2D backButton, Texture2D backButtonPressed)
	{
		Vector2 mousePosition = GetMousePosition();
#ifdef _DEBUG
		DrawRectangleV(back.position, back.size, VIOLET);
#endif
		DrawTextureEx(backButton, back.textPosition, 0, 0.07f, WHITE);

		if (CheckCollisionMouseButton(mousePosition, back.position.x, back.position.y, back.size.y, back.size.x))
		{
#ifdef _DEBUG
			DrawRectangleV(back.position, back.size, BLUE);
#endif
			DrawTextureEx(backButtonPressed, back.textPosition, 0, 0.07f, WHITE);
		}
	}

	void PauseButton(Texture2D pauseButton, Texture2D pauseButtonPressed)
	{
		Vector2 mousePosition = GetMousePosition();
#ifdef _DEBUG
		DrawRectangleV(back.position, back.size, VIOLET);
#endif
		DrawTextureEx(pauseButton, back.textPosition, 0, 0.07f, WHITE);

		if (CheckCollisionMouseButton(mousePosition, back.position.x, back.position.y, back.size.y, back.size.x))
		{
#ifdef _DEBUG
			DrawRectangleV(back.position, back.size, BLUE);
#endif
			DrawTextureEx(pauseButtonPressed, back.textPosition, 0, 0.07f, WHITE);
		}
	}

}