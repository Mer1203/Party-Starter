#include "ScreenMenu.h"
#include "raylib.h"

namespace Asteroids
{
	void MenuDraw(Texture2D backgroundMenu)
	{
		DrawTexture(backgroundMenu, 0, 0, WHITE);
	}
}