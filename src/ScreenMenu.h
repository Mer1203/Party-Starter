#pragma once
#include "raylib.h"

namespace Asteroids
{
	struct Tittle
	{
		Vector2 position;
		Vector2 size;
		float fontSize;
		float spacing;
	};

	extern Tittle tittleOne;
	extern Tittle tittleTwo;

	void MenuInit();
	void MenuDraw(Texture2D backgroundMenu, Texture2D playButton, Texture2D rulesButton,
		Texture2D creditsButton, Texture2D exitButton, Texture2D playPressedButton,
		Texture2D rulesPressedButton, Texture2D creditsPressedButton, Texture2D exitPressedButton,
		Font font);
}