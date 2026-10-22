#include "ScreenMenu.h"
#include "Button.h"
#include "raylib.h"

namespace Asteroids
{
	Tittle tittleOne;
	Tittle tittleTwo;

	void MenuInit()
	{
		tittleOne.position.x = 160;
		tittleOne.position.y = 30;
		tittleOne.fontSize = 120;
		tittleOne.spacing = 1;

		tittleTwo.position.x = 165;
		tittleTwo.position.y = 30;
		tittleTwo.fontSize = 120;
		tittleTwo.spacing = 1;
	}

	void MenuDraw(Texture2D backgroundMenu, Texture2D playButton, Texture2D rulesButton, 
		Texture2D creditsButton, Texture2D exitButton, Texture2D playPressedButton, 
		Texture2D rulesPressedButton, Texture2D creditsPressedButton, Texture2D exitPressedButton, Font font)
	{
		Vector2 mousePosition = GetMousePosition();

		DrawTexture(backgroundMenu, 0, 0, WHITE);

		DrawTextEx(font, "PARTY STARTER!", tittleTwo.position, tittleTwo.fontSize, tittleTwo.spacing, BLACK);
		DrawTextEx(font, "PARTY STARTER!", tittleOne.position, tittleOne.fontSize, tittleOne.spacing, PINK);

		ButtonDraw(mousePosition, playButton, rulesButton, creditsButton, exitButton, playPressedButton, 
			       rulesPressedButton, creditsPressedButton, exitPressedButton);
		ButtonTextDraw(font);
		
	}
}