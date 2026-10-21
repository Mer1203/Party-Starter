#include "ScreenPlay.h"
#include "Player.h"
#include "Bullets.h"
#include "raylib.h"

void GameplayDraw(Texture2D backgroundGameplay, Texture2D canion, Texture2D confetti)
{
	DrawTexture(backgroundGameplay, 0, 0, WHITE);
	BulletsDraw(confetti);
	PlayerDraw(canion);
}