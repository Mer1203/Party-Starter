#pragma once

enum class Screen
{
	Menu = 0,
	Play,
	Rules,
	Credits,
	Exit
};

extern Screen currentScreen;

void Draw();
void Update(float delta, bool& gameIsRunning);