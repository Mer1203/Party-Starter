#include "ScreenPlay.h"
#include "Asteroids.h"
#include "Bullets.h"
#include "Player.h"
#include "raylib.h"

namespace Asteroids
{
	void GameplayDraw(Texture2D backgroundGameplay, Texture2D canion, Texture2D confetti, 
		Texture2D piñataOne, Texture2D piñataTwo, Texture2D piñataThree)
	{
		DrawTexture(backgroundGameplay, 0, 0, WHITE);

		BigAsteroidDraw(piñataOne);
		MiddleAsteroidDraw(piñataTwo);
		SmallAsteroidDraw(piñataThree);

		BulletsDraw(confetti);
		PlayerDraw(canion);
	}
}