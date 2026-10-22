#pragma once
#include "raylib.h"

namespace Asteroids
{
	void MenuDraw(Texture2D backgroundMenu, Texture2D playButton, Texture2D rulesButton,
		Texture2D creditsButton, Texture2D exitButton, Texture2D playPressedButton,
		Texture2D rulesPressedButton, Texture2D creditsPressedButton, Texture2D exitPressedButton);
}