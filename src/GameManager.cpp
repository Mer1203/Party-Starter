#include "GameManager.h"
#include "ScreenMenu.h"
#include "Player.h"
#include "Button.h"
#include "raylib.h"

Screen currentScreen = Screen::Menu;

void Update(float delta)
{

	// UPDATE:
	switch (currentScreen)
	{
	case Screen::Menu:
		//Inicio los valores de todos los botones:
		ButtonInit();

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
		break;
	default:
		break;
	}
}

void Draw()
{
	Vector2 mousePosition = GetMousePosition();

	//DIBUJADO:
	BeginDrawing();
	ClearBackground(WHITE);

	switch (currentScreen)
	{
	case Screen::Menu:
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