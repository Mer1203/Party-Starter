#pragma once
#include "GameManager.h"
#include "raylib.h"

namespace Asteroids
{
	struct Button
	{
		int x;
		int y;
		int textX;
		int textY;
		int textSize;
		int width;
		int height;
		bool isPressed;
	};

	extern Button play;
	extern Button rules;
	extern Button credits;
	extern Button exitGame;
	extern Button back;

	void ButtonInit();

	bool CheckCollisionMouseButton(Vector2 mousePosition, int buttonX, int buttonY, int buttonHeight, int buttonWidth);
	void IsMousePressed();
	void IsMousePressingBackButton();

	void ButtonDraw(Vector2 MousePosition);;
	void ButtonTextDraw(Vector2 MousePosition);

	void BackMenuButton();
}