#pragma once
#include "raylib.h"

enum class Screen
{
	Menu = 0,
	Play,
	Rules,
	Credits,
	Exit
};

extern Screen currentScreen;

void Draw(Texture2D backgroundMenu, Texture2D backgroundGameplay);
void Update(float delta, bool& gameIsRunning);