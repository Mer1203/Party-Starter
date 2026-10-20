#include "ScreenPlay.h"
#include "Player.h"
#include "raylib.h"

void GameplayUpdate()
{

}

void GameplayDraw(Texture2D backgroundGameplay)
{
	DrawTexture(backgroundGameplay, 0, 0, WHITE);

#ifdef _DEBUG
	PlayerDraw();
#endif
}