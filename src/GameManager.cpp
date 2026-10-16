#include "GameManager.h"
#include "ScreenMenu.h"
#include "Button.h"
#include "raylib.h"

void Draw()
{
	Vector2 MousePosition = GetMousePosition();

	//DIBUJADO:
	BeginDrawing();
	switch (currentScreen)
	{
	case Screen::Menu:
		ButtonDrawing(MousePosition);
		ButtonText(MousePosition);
		break;
	case Screen::Play:
		BackMenuButton();
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
}

void Update()
{
	// UPDATE:
	switch (currentScreen)
	{
	case Screen::Menu:
		GetMousePosition();
		IsMousePressed();
		break;
	case Screen::Play:
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