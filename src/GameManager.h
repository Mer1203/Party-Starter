#pragma once
#include "raylib.h"

namespace Asteroids
{
	enum class Screen
	{
		Menu = 0,
		Play,
		Rules,
		Credits,
		Exit,
		Pause,
		GameOver,
	};

	extern Screen currentScreen;

	void Draw(Texture2D backgroundMenu, Texture2D backgroundGameplay, Texture2D canion,
		Texture2D confetti, Texture2D playButton, Texture2D rulesButton, Texture2D creditsButton,
		Texture2D exitButton, Texture2D playPressedButton, Texture2D rulesPressedButton,
		Texture2D creditsPressedButton, Texture2D exitPressedButton, Font font, Texture2D piñataOne, 
		Texture2D piñataTwo, Texture2D piñataThree, Texture2D backButton, Texture2D backButtonPressed, 
		Texture2D pauseButton, Texture2D pauseButtonPressed, Texture2D pauseButtonScreen,
		Texture2D pauseButtonScreenPressed, Texture2D linkButton, Texture2D linkButtonPressed);

	void Update(float delta, bool& gameIsRunning, Texture2D canion, Sound menuButtonsSound);
}