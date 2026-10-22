#include "ScreenMenu.h"
#include "Button.h"
#include "raylib.h"

namespace Asteroids
{
	void MenuDraw(Texture2D backgroundMenu, Texture2D playButton, Texture2D rulesButton, 
		Texture2D creditsButton, Texture2D exitButton, Texture2D playPressedButton, 
		Texture2D rulesPressedButton, Texture2D creditsPressedButton, Texture2D exitPressedButton)
	{
		Vector2 mousePosition = GetMousePosition();

		DrawTexture(backgroundMenu, 0, 0, WHITE);
		ButtonDraw(mousePosition, playButton, rulesButton, creditsButton, exitButton, playPressedButton, 
			       rulesPressedButton, creditsPressedButton, exitPressedButton);
		//ButtonTextDraw(mousePosition);
	}
}