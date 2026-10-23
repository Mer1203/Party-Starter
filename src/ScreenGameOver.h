#pragma once
#include "raylib.h"

namespace Asteroids
{
	struct GameOver
	{
		Vector2 position;
		Vector2 text;
		Vector2 size;
		float fontSize;
		float spacing;
	};

	extern GameOver gameOverText;
	extern GameOver pointsText;
	extern GameOver retryButton;
	extern GameOver menuButtonGO;

	void GameOverInit();
	void GameOverUpdate(Texture2D canion, Sound menuButtonsSound);
	void GameOverDraw(Texture2D backgroundGameplay, Texture2D canion, Texture2D confetti,
		Texture2D piniataOne, Texture2D piniataTwo, Texture2D piniataThree, Font font,
		Texture2D pauseButtonScreen, Texture2D pauseButtonScreenPressed);

}