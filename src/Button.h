#pragma once
#include "GameManager.h"
#include "raylib.h"

namespace Asteroids
{
	struct Button
	{
		Vector2 position;
		Vector2 size;
		int textX;
		int textY;
		int textSize;
		bool isPressed;
	};

	extern Button play;
	extern Button rules;
	extern Button credits;
	extern Button exitGame;
	extern Button back;

	void ButtonInit();

	bool CheckCollisionMouseButton(Vector2 mousePosition, float buttonX, float buttonY, float buttonHeight, float buttonWidth);
	void IsMousePressed();
	void IsMousePressingBackButton();

	void ButtonDraw(Vector2 mousePosition, Texture2D playButton, Texture2D rulesButton, Texture2D creditsButton,
		Texture2D exitButton, Texture2D playPressedButton, Texture2D rulesPressedButton, Texture2D creditsPressedButton,
		Texture2D exitPressedButton);
	void ButtonTextDraw(Vector2 MousePosition);

	void BackMenuButton();
}