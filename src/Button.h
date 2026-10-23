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
	extern Button pause;
	extern Button fontLink;
	extern Button soundOneLink;
	extern Button soundTwoLink;

	void ButtonInit();

	bool CheckCollisionMouseButton(Vector2 mousePosition, float buttonX, float buttonY, float buttonHeight, float buttonWidth);
	void IsMousePressed(Sound menuButtonsSound);
	void IsMousePressingBackButton();
	void IsMousePressingPauseButton();
	void IsMousePressingLinkButtons();

	void ButtonDraw(Vector2 mousePosition, Texture2D playButton, Texture2D rulesButton, Texture2D creditsButton,
		Texture2D exitButton, Texture2D playPressedButton, Texture2D rulesPressedButton, Texture2D creditsPressedButton,
		Texture2D exitPressedButton);
	void ButtonTextDraw(Font font);

	void LinkButtonDraw(Vector2 mousePosition, Texture2D linkButton, Texture2D linkButtonPressed);
	void BackButton(Texture2D backButton, Texture2D backButtonPressed);
	void PauseButton(Texture2D pauseButton, Texture2D pauseButtonPressed);
}