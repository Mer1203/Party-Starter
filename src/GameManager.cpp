#include "GameManager.h"
#include "ScreenMenu.h"
#include "ScreenExit.h"
#include "Asteroids.h"
#include "Player.h"
#include "Button.h"
#include "raylib.h"

Screen currentScreen = Screen::Menu;

void Update(float delta, bool& gameIsRunning)
{
	// UPDATE:
	switch (currentScreen)
	{
	case Screen::Menu:
		//Inicio los valores de todos los botones:
		ButtonInit();
		PlayerInit();
		AsteroidsInit();

		GetMousePosition();
		IsMousePressed();
		break;
	case Screen::Play:
		PlayerUpdate(delta);
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

void Draw(Texture2D backgroundMenu)
{
	Vector2 mousePosition = GetMousePosition();

	//DIBUJADO:
	BeginDrawing();
	ClearBackground(WHITE);

	switch (currentScreen)
	{
	case Screen::Menu:
		DrawTexture(backgroundMenu, 0, 0, WHITE);
		ButtonDraw(mousePosition);
		ButtonTextDraw(mousePosition);
		break;
	case Screen::Play:
		//Provisorio, despues cambiar a boton de pausa!
		BackMenuButton();

		PlayerDraw();
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