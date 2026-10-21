#include "GameManager.h"
#include "ScreenMenu.h"
#include "ScreenExit.h"
#include "ScreenPlay.h"
#include "Asteroids.h"
#include "Bullets.h"
#include "Player.h"
#include "Button.h"
#include "raylib.h"

Screen currentScreen = Screen::Menu;

void Update(float delta, bool& gameIsRunning, Texture2D canion)
{
	// UPDATE:
	switch (currentScreen)
	{
	case Screen::Menu:
		//Inicio los valores de todos los botones:
		ButtonInit();
		PlayerInit(canion);
		//AsteroidsInit();
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			BulletsInit(bullets[i]);
		}

		GetMousePosition();
		IsMousePressed();
		break;
	case Screen::Play:
		PlayerUpdate(delta);
		ShotBullet(delta);
		IsMousePressingBackButton();
		break;
	case Screen::Rules:
		IsMousePressingBackButton();
		break;
	case Screen::Credits:
		IsMousePressingBackButton();
		break;
	case Screen::Exit:
		ExitUpdate(gameIsRunning);
		break;
	default:
		break;
	}
}

void Draw(Texture2D backgroundMenu, Texture2D backgroundGameplay, Texture2D canion)
{
	Vector2 mousePosition = GetMousePosition();

	//DIBUJADO:
	BeginDrawing();
	ClearBackground(WHITE);

	switch (currentScreen)
	{
	case Screen::Menu:
		MenuDraw(backgroundMenu);
		ButtonDraw(mousePosition);
		ButtonTextDraw(mousePosition);
		break;
	case Screen::Play:
		GameplayDraw(backgroundGameplay, canion);
		//Provisorio, despues cambiar a boton de pausa!
		BackMenuButton();
		BulletsDraw();
		break;
	case Screen::Rules:
		BackMenuButton();
		break;
	case Screen::Credits:
		BackMenuButton();
		break;
	case Screen::Exit:
		break;
	default:
		break;
	}

	EndDrawing();
}