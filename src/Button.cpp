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
		play.textX = 770;
		play.textY = 200;
		play.textSize = 40;
		play.size.y = 80; //height
		play.size.x = 280; //width

		rules.isPressed = false;
		rules.position.x = 700;
		rules.position.y = 310;
		rules.textX = 760;
		rules.textY = 330;
		rules.textSize = 40;
		rules.size.y = 80;
		rules.size.x = 280;

		credits.isPressed = false;
		credits.position.x = 700;
		credits.position.y = 440;
		credits.textX = 730;
		credits.textY = 460;
		credits.textSize = 40;
		credits.size.y = 80;
		credits.size.x = 280;

		exitGame.isPressed = false;
		exitGame.position.x = 700;
		exitGame.position.y = 570;
		exitGame.textX = 780;
		exitGame.textY = 590;
		exitGame.textSize = 40;
		exitGame.size.y = 80;
		exitGame.size.x = 280;

		back.position.x = 0;
		back.position.y = 0;
		back.size.y = 70;
		back.size.x = 70;
		back.textX = 10;
		back.textY = 6;
		back.textSize = 20;
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

	void ButtonTextDraw(Vector2 mousePosition)
	{
		DrawText(TextFormat("JUGAR"), play.textX, play.textY, play.textSize, BLUE);
		DrawText(TextFormat("REGLAS"), rules.textX, rules.textY, rules.textSize, BLUE);
		DrawText(TextFormat("CREDITOS"), credits.textX, credits.textY, credits.textSize, BLUE);
		DrawText(TextFormat("SALIR"), exitGame.textX, exitGame.textY, exitGame.textSize, BLUE);

		if (CheckCollisionMouseButton(mousePosition, play.position.x, play.position.y, play.size.y, play.size.x))
		{
			DrawText(TextFormat("JUGAR"), play.textX, play.textY, play.textSize, VIOLET);
		}
		else if (CheckCollisionMouseButton(mousePosition, rules.position.x, rules.position.y, rules.size.y, rules.size.x))
		{
			DrawText(TextFormat("REGLAS"), rules.textX, rules.textY, rules.textSize, VIOLET);
		}
		else if (CheckCollisionMouseButton(mousePosition, credits.position.x, credits.position.y, credits.size.y, credits.size.x))
		{
			DrawText(TextFormat("CREDITOS"), credits.textX, credits.textY, credits.textSize, VIOLET);
		}
		else if (CheckCollisionMouseButton(mousePosition, exitGame.position.x, exitGame.position.y, exitGame.size.y, exitGame.size.x))
		{
			DrawText(TextFormat("SALIR"), exitGame.textX, exitGame.textY, exitGame.textSize, VIOLET);
		}
	}

	void BackMenuButton()
	{
		Vector2 mousePosition = GetMousePosition();
		DrawRectangleV(back.position, back.size, VIOLET);

		if (CheckCollisionMouseButton(mousePosition, back.position.x, back.position.y, back.size.y, back.size.x))
		{
			DrawRectangleV(back.position, back.size, BLUE);
		}

		DrawText(TextFormat("ATRAS"), back.textX, back.textY, back.textSize, BLUE);

		if (CheckCollisionMouseButton(mousePosition, back.position.x, back.position.y, back.size.y, back.size.x))
		{
			DrawText(TextFormat("ATRAS"), back.textX, back.textY, back.textSize, VIOLET);
		}
	}
}