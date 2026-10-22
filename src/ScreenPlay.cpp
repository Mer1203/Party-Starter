#include "ScreenPlay.h"
#include "Asteroids.h"
#include "Bullets.h"
#include "Player.h"
#include "raylib.h"

namespace Asteroids
{
	void GameplayDraw(Texture2D backgroundGameplay, Texture2D canion, Texture2D confetti)
	{
		DrawTexture(backgroundGameplay, 0, 0, WHITE);

		BigAsteroidDraw();
		MiddleAsteroidDraw();
		SmallAsteroidDraw();

		BulletsDraw(confetti);
		PlayerDraw(canion);
	}
}