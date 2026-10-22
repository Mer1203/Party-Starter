#include "ScreenRules.h"
#include "raylib.h"

namespace Asteroids
{
	void RulesDraw(Texture backgroundGameplay)
	{
		DrawTexture(backgroundGameplay, 0, 0, WHITE);
	}
}