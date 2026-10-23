#include "ScreenRules.h"
#include "Game.h"
#include <string>
#include "raylib.h"

namespace Asteroids
{
	void DrawCenteredText(Font font, std::string text, float y, float fontSize)
	{
		float spacing = 2.0f;

		Vector2 textSize = MeasureTextEx(font, text.c_str(), fontSize, spacing);
		Vector2 textPosition = { (WINDOW_WIDTH - textSize.x) / 2.0f, y };

		DrawTextEx(font, text.c_str(), textPosition, fontSize, spacing, WHITE);
	}

	void RulesDraw(Texture2D backgroundGameplay, Font font)
	{
		DrawTexture(backgroundGameplay, 0, 0, WHITE);

		float titleSize = 40.0f;
		float textSize = 30.0f;

		DrawCenteredText(font, "Controls:", 100, titleSize);
		DrawCenteredText(font, "Hold right click to move and aim", 155, textSize);
		DrawCenteredText(font, "Left click to shoot confetti", 200, textSize);

		DrawCenteredText(font, "Goal:", 290, titleSize);
		DrawCenteredText(font, "Score as many points as you can!", 345, textSize);

		DrawCenteredText(font, "Careful!", 440, titleSize);
		DrawCenteredText(font, "If a pinata touches your cannon,", 495, textSize);
		DrawCenteredText(font, "you lose a life.", 540, textSize);
		DrawCenteredText(font, "If you run out of lives, you lose!", 595, textSize);
	}
}