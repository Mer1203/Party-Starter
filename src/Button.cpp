#include "Button.h"
#include "raylib.h"

Button play;
Button rules;
Button credits;
Button exitGame;
Button back;

void ButtonInit()
{
	play.isPressed = false;
	play.x = 700;
	play.y = 180;
	play.textX = 770;
	play.textY = 200;
	play.textSize = 40;
	play.height = 80;
	play.width = 280;

	rules.isPressed = false;
	rules.x = 700;
	rules.y = 310;
	rules.textX = 760;
	rules.textY = 330;
	rules.textSize = 40;
	rules.height = 80;
	rules.width = 280;

	credits.isPressed = false;
	credits.x = 700;
	credits.y = 440;
	credits.textX = 730;
	credits.textY = 460;
	credits.textSize = 40;
	credits.height = 80;
	credits.width = 280;

	exitGame.isPressed = false;
	exitGame.x = 700;
	exitGame.y = 570;
	exitGame.textX = 780;
	exitGame.textY = 590;
	exitGame.textSize = 40;
	exitGame.height = 80;
	exitGame.width = 280;

	back.x = 0;
	back.y = 0;
	back.width = 90;
	back.height = 30;
	back.textX = 10;
	back.textY = 6;
	back.textSize = 20;
}

bool CheckCollisionMouseButton(Vector2 mousePosition, int buttonX, int buttonY, int buttonHeight, int buttonWidth)
{
	return buttonX <= mousePosition.x && buttonX + buttonWidth >= mousePosition.x
		&& mousePosition.y >= buttonY && mousePosition.y <= buttonY + buttonHeight;
}

void IsMousePressed()
{
	Vector2 mousePosition = GetMousePosition();

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		if (CheckCollisionMouseButton(mousePosition, play.x, play.y, play.height, play.width))
		{
			currentScreen = Screen::Play;
		}
		else if (CheckCollisionMouseButton(mousePosition, rules.x, rules.y, rules.height, rules.width))
		{
			currentScreen = Screen::Rules;
		}
		else if (CheckCollisionMouseButton(mousePosition, credits.x, credits.y, credits.height, credits.width))
		{
			currentScreen = Screen::Credits;
		}
		else if (CheckCollisionMouseButton(mousePosition, exitGame.x, exitGame.y, exitGame.height, exitGame.width))
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
		if (CheckCollisionMouseButton(mousePosition, back.x, back.y, back.height, back.width))
		{
			currentScreen = Screen::Menu;
		}
	}
}

void ButtonDraw(Vector2 mousePosition)
{
	//DIBUJO BOTONES
	DrawRectangle(play.x, play.y, play.width, play.height, VIOLET);
	DrawRectangle(rules.x, rules.y, rules.width, rules.height, VIOLET);
	DrawRectangle(credits.x, credits.y, credits.width, credits.height, VIOLET);
	DrawRectangle(exitGame.x, exitGame.y, exitGame.width, exitGame.height, VIOLET);

	if (CheckCollisionMouseButton(mousePosition, play.x, play.y, play.height, play.width))
	{
		DrawRectangle(play.x, play.y, play.width, play.height, BLUE);
	}
	else if (CheckCollisionMouseButton(mousePosition, rules.x, rules.y, rules.height, rules.width))
	{
		DrawRectangle(rules.x, rules.y, rules.width, rules.height, BLUE);
	}
	else if (CheckCollisionMouseButton(mousePosition, credits.x, credits.y, credits.height, credits.width))
	{
		DrawRectangle(credits.x, credits.y, credits.width, credits.height, BLUE);
	}
	else if (CheckCollisionMouseButton(mousePosition, exitGame.x, exitGame.y, exitGame.height, exitGame.width))
	{
		DrawRectangle(exitGame.x, exitGame.y, exitGame.width, exitGame.height, BLUE);
	}
}

void ButtonTextDraw(Vector2 mousePosition)
{
	DrawText(TextFormat("JUGAR"), play.textX, play.textY, play.textSize, BLUE);
	DrawText(TextFormat("REGLAS"), rules.textX, rules.textY, rules.textSize, BLUE);
	DrawText(TextFormat("CREDITOS"), credits.textX, credits.textY, credits.textSize, BLUE);
	DrawText(TextFormat("SALIR"), exitGame.textX, exitGame.textY, exitGame.textSize, BLUE);

	if (CheckCollisionMouseButton(mousePosition, play.x, play.y, play.height, play.width))
	{
		DrawText(TextFormat("JUGAR"), play.textX, play.textY, play.textSize, VIOLET);
	}
	else if (CheckCollisionMouseButton(mousePosition, rules.x, rules.y, rules.height, rules.width))
	{
		DrawText(TextFormat("REGLAS"), rules.textX, rules.textY, rules.textSize, VIOLET);
	}
	else if (CheckCollisionMouseButton(mousePosition, credits.x, credits.y, credits.height, credits.width))
	{
		DrawText(TextFormat("CREDITOS"), credits.textX, credits.textY, credits.textSize, VIOLET);
	}
	else if (CheckCollisionMouseButton(mousePosition, exitGame.x, exitGame.y, exitGame.height, exitGame.width))
	{
		DrawText(TextFormat("SALIR"), exitGame.textX, exitGame.textY, exitGame.textSize, VIOLET);
	}
}

void BackMenuButton()
{
	Vector2 mousePosition = GetMousePosition();

	DrawRectangle(back.x, back.y, back.width, back.height, VIOLET);

	if (CheckCollisionMouseButton(mousePosition, back.x, back.y, back.height, back.width))
	{
		DrawRectangle(back.x, back.y, back.width, back.height, BLUE);
	}

	DrawText(TextFormat("ATRAS"), back.textX, back.textY, back.textSize, BLUE);

	if (CheckCollisionMouseButton(mousePosition, back.x, back.y, back.height, back.width))
	{
		DrawText(TextFormat("ATRAS"), back.textX, back.textY, back.textSize, VIOLET);
	}
}