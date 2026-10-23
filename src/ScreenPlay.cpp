#include "ScreenPlay.h"
#include "Asteroids.h"
#include "Bullets.h"
#include "Player.h"
#include "raylib.h"

namespace Asteroids
{
	Text pointsTextOne;
	Text pointsTextTwo;
	Text livesTextOne;
	Text livesTextTwo;

	void GameplayInit()
	{
		pointsTextOne.text.x = 780;
		pointsTextOne.text.y = 20;
		pointsTextOne.fontSize = 30;
		pointsTextOne.spacing = 2;

		pointsTextTwo.text.x = 782;
		pointsTextTwo.text.y = 20;
		pointsTextTwo.fontSize = 30;
		pointsTextTwo.spacing = 2;
		
		livesTextOne.text.x = 80;
		livesTextOne.text.y = 20;
		livesTextOne.fontSize = 30;
		livesTextOne.spacing = 2;

		livesTextTwo.text.x = 82;
		livesTextTwo.text.y = 20;
		livesTextTwo.fontSize = 30;
		livesTextTwo.spacing = 2;
	}

	void GameplayDraw(Texture2D backgroundGameplay, Texture2D canion, Texture2D confetti, 
		Texture2D piñataOne, Texture2D piñataTwo, Texture2D piñataThree, Font font)
	{
		DrawTexture(backgroundGameplay, 0, 0, WHITE);

		BigAsteroidDraw(piñataOne);
		MiddleAsteroidDraw(piñataTwo);
		SmallAsteroidDraw(piñataThree);

		BulletsDraw(confetti);
		PlayerDraw(canion);

		DrawTextEx(font, TextFormat("Score: %i", player.score), pointsTextTwo.text, pointsTextTwo.fontSize, pointsTextTwo.spacing, BLACK);
		DrawTextEx(font, TextFormat("Score: %i", player.score), pointsTextOne.text, pointsTextOne.fontSize, pointsTextOne.spacing, WHITE);

		DrawTextEx(font, TextFormat("Lives: %i", player.lives), livesTextOne.text, livesTextOne.fontSize, livesTextOne.spacing, BLACK);
		DrawTextEx(font, TextFormat("Lives: %i", player.lives), livesTextTwo.text, livesTextTwo.fontSize, livesTextTwo.spacing, WHITE);
	}
}