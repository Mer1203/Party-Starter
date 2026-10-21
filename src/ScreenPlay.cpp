#include "ScreenPlay.h"
#include "Player.h"
#include "raylib.h"

void GameplayUpdate()
{

}

void GameplayDraw(Texture2D backgroundGameplay, Texture2D canion)
{
	DrawTexture(backgroundGameplay, 0, 0, WHITE);
	PlayerDraw(canion);
}