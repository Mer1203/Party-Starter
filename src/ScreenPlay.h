#pragma once
#include "raylib.h"

namespace Asteroids
{
	struct Text
	{
		Vector2 position;
		Vector2 size;
		Vector2 text;
		float fontSize;
		float spacing;
	};

	extern Text pointsTextOne;
	extern Text pointsTextTwo;

	extern Text livesTextOne;
	extern Text livesTextTwo;

	void GameplayDraw(Texture2D backgroundGameplay, Texture2D caion, 
		Texture2D confetti, Texture2D piñataOne, Texture2D piñataTwo, 
		Texture2D piñataThree, Font font);
	void GameplayInit();
}