#include "ScreenCredits.h"
#include "raylib.h"

namespace Asteroids
{
	void CreditsDraw(Texture2D backgroundGameplay)
	{
		DrawTexture(backgroundGameplay, 0, 0, WHITE);
	}
}