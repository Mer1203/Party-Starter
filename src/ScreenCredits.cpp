#include "ScreenCredits.h"
#include "Game.h"
#include "Button.h"
#include <string>
#include "raylib.h"

namespace Asteroids
{
	namespace
	{
		void DrawCenteredText(Font font, std::string text, float y, float fontSize)
		{
			float spacing = 2.0f;

			Vector2 textSize = MeasureTextEx(font, text.c_str(), fontSize, spacing);
			Vector2 textPosition = { (WINDOW_WIDTH - textSize.x) / 2.0f, y };

			DrawTextEx(font, text.c_str(), textPosition, fontSize, spacing, WHITE);
		}
	}

	void CreditsDraw(Texture2D backgroundGameplay, Font font, Texture2D linkButton, Texture2D linkButtonPressed)
	{
		DrawTexture(backgroundGameplay, 0, 0, WHITE);

		float titleSize = 40.0f;
		float textSize = 32.0f;
		float smallTextSize = 26.0f;
		float linkTextSize = 20.0f;

		DrawCenteredText(font, "Game Developed by:", 30, titleSize);
		DrawCenteredText(font, "Mercedes Ramirez Diaz", 80, textSize);

		DrawCenteredText(font, "Art by:", 140, titleSize);
		DrawCenteredText(font, "Lucia Martinez De La Rosa", 190, textSize);
		DrawCenteredText(font, "Matias Toniolo", 230, textSize);

		DrawCenteredText(font, "Font:", 290, titleSize);
		DrawCenteredText(font, "Super Wonder - dafont", 340, textSize);

		DrawCenteredText(font, "Sounds:", 440, titleSize);
		DrawCenteredText(font, "Confetti Pop - Myinstants", 490, textSize);
		DrawCenteredText(font, "meme camioneta payaso - Myinstants", 590, textSize);

		DrawCenteredText(font, "Used AI generation - Claude to help with Rules and Credits and bugs.", 710, smallTextSize);

		//Botones chicos con el link:
		LinkButtonDraw(GetMousePosition(), linkButton, linkButtonPressed);

		DrawCenteredText(font, "LINK", fontLink.position.y + 7, linkTextSize);
		DrawCenteredText(font, "LINK", soundOneLink.position.y + 7, linkTextSize);
		DrawCenteredText(font, "LINK", soundTwoLink.position.y + 7, linkTextSize);
	}
}