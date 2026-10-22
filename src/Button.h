#pragma once
#include "GameManager.h"
#include "raylib.h"

namespace Asteroids
{
	struct Button
	{
		Vector2 position;
		Vector2 textPosition;
		Vector2 size;
		int textSize;
		bool isPressed;
		float fontSize;
		float spacing;
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
	void ButtonTextDraw(Font font);

	void BackButton(Texture2D backButton, Texture2D backButtonPressed);
}