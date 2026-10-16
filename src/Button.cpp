#include "Button.h"
#include "GameManager.h"
#include "raylib.h"

Screen currentScreen = Screen::Menu;

void ButtonInit()
{
	play.isPressed = false;
	play.x = 300;
	play.y = 180;
	play.textX = 344;
	play.textY = 200;
	play.textSize = 40;
	play.height = 60;
	play.height = 200;

	rules.isPressed = false;
	rules.x = 300;
	rules.y = 280;
	rules.textX = 330;
	rules.textY = 300;
	rules.textSize = 40;
	rules.height = 60;
	rules.height = 200;

	credits.isPressed = false;
	credits.x = 300;
	credits.y = 380;
	credits.textX = 304;
	credits.textY = 400;
	credits.textSize = 40;
	credits.height = 60;
	credits.height = 200;

	exit.isPressed = false;
	exit.x = 300;
	exit.y = 480;
	exit.textX = 345;
	exit.textY = 500;
	exit.textSize = 40;
	exit.height = 60;
	exit.height = 200;

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
	Vector2 MousePosition = GetMousePosition();

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		if (CheckCollisionMouseButton(MousePosition, play.x, play.y, play.height, play.width))
		{
			currentScreen = Screen::Play;
		}
		else if (CheckCollisionMouseButton(MousePosition, rules.x, rules.y, rules.height, rules.width))
		{
			currentScreen = Screen::Rules;
		}
		else if (CheckCollisionMouseButton(MousePosition, credits.x, credits.y, credits.height, credits.width))
		{
			currentScreen = Screen::Credits;
		}
		else if (CheckCollisionMouseButton(MousePosition, exit.x, exit.y, exit.height, exit.width))
		{
			currentScreen = Screen::Exit;
		}
	}
}

void IsMousePressingBackButton()
{
	Vector2 MousePosition = GetMousePosition();

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		if (CheckCollisionMouseButton(MousePosition, back.x, back.y, back.height, back.width))
		{
			currentScreen = Screen::Menu;
		}
	}
}

void ButtonDrawing(Vector2 MousePosition)
{
	//DIBUJO BOTONES
	DrawRectangle(play.x, play.y, play.width, play.height, VIOLET);
	DrawRectangle(rules.x, rules.y, rules.width, rules.height, VIOLET);
	DrawRectangle(credits.x, credits.y, credits.width, credits.height, VIOLET);
	DrawRectangle(exit.x, exit.y, exit.width, exit.width, VIOLET);

	if (CheckCollisionMouseButton(MousePosition, play.x, play.y, play.height, play.width))
	{
		DrawRectangle(play.x, play.y, play.height, play.width, BLUE);
	}
	else if (CheckCollisionMouseButton(MousePosition, rules.x, rules.y, rules.height, rules.width))
	{
		DrawRectangle(rules.x, rules.y, rules.width, rules.height, BLUE);
	}
	else if (CheckCollisionMouseButton(MousePosition, credits.x, credits.y, credits.height, credits.width))
	{
		DrawRectangle(credits.x, credits.y, credits.width, credits.width, BLUE);
	}
	else if (CheckCollisionMouseButton(MousePosition, exit.x, exit.y, exit.height, exit.width))
	{
		DrawRectangle(exit.x, exit.y, exit.width, exit.height, BLUE);
	}
}

void ButtonText(Vector2 MousePosition)
{
	DrawText(TextFormat("JUGAR"), play.textX, play.textY, play.textSize, BLUE);
	DrawText(TextFormat("REGLAS"), rules.textX, rules.textY, rules.textSize, BLUE);
	DrawText(TextFormat("CREDITOS"), credits.textX, credits.textY, credits.textSize, BLUE);
	DrawText(TextFormat("SALIR"), exit.textX, exit.textY, exit.textSize, BLUE);

	if (CheckCollisionMouseButton(MousePosition, play.x, play.y, play.height, play.width))
	{
		DrawText(TextFormat("JUGAR"), play.textX, play.textY, play.textSize, VIOLET);
	}
	else if (CheckCollisionMouseButton(MousePosition, rules.x, rules.y, rules.height, rules.width))
	{
		DrawText(TextFormat("REGLAS"), rules.textX, rules.textY, rules.textSize, VIOLET);
	}
	else if (CheckCollisionMouseButton(MousePosition, credits.x, credits.y, credits.height, credits.width))
	{
		DrawText(TextFormat("CREDITOS"), credits.textX, credits.textY, credits.textSize, VIOLET);
	}
	else if (CheckCollisionMouseButton(MousePosition, exit.x, exit.y, exit.height, exit.width))
	{
		DrawText(TextFormat("SALIR"), exit.textX, exit.textY, exit.textSize, VIOLET);
	}
}

void BackMenuButton()
{
	Vector2 MousePosition = GetMousePosition();

	DrawRectangle(back.x, back.y, back.width, back.height, VIOLET);

	if (CheckCollisionMouseButton(MousePosition, back.x, back.y, back.height, back.width))
	{
		DrawRectangle(back.x, back.y, back.width, back.height, BLUE);
	}

	DrawText(TextFormat("ATRAS"), back.textX, back.textY, back.textSize, BLUE);

	if (CheckCollisionMouseButton(MousePosition, back.x, back.y, back.height, back.width))
	{
		DrawText(TextFormat("ATRAS"), back.textX, back.textY, back.textSize, VIOLET);
	}
}



