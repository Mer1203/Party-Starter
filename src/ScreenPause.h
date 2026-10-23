#pragma once
#include "raylib.h"

namespace Asteroids
{
	struct Pause
	{
		Vector2 position;
		Vector2 text;
		Vector2 size;
		float fontSize;
		float spacing;
	};

	extern Pause pauseText;
	extern Pause continueButton;
	extern Pause menuButton;

	void PauseInit();
	void PauseDraw(Texture2D backgroundGameplay, Texture2D canion, 
		Texture2D confetti, Texture2D piniataOne, Texture2D piniataTwo,
		Texture2D piniataThree, Font font, Texture2D pauseButtonScreen,
		Texture2D pauseButtonScreenPressed);
	void IsMousePressingButtonPause();
}