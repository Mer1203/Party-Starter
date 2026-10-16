#include "Button.h"
#include "GameManager.h"
#include "raylib.h"

Screen currentScreen = Screen::Menu;

bool CheckCollisionMouseButton(Vector2 mousePosition, int buttonX, int buttonY, int buttonHeight, int buttonWidth)
{
	return buttonX <= mousePosition.x && buttonX + buttonWidth >= mousePosition.x
		&& mousePosition.y >= buttonY && mousePosition.y <= buttonY + buttonHeight;
}

void IsMousePressed()
{
	Vector2 MousePosition = GetMousePosition();

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		if (CheckCollisionMouseButton(MousePosition, positionButtonX, positionButtonPlayY, heightButton, widthButton))
		{
			currentScreen = Screen::Play;
		}
		else if (CheckCollisionMouseButton(MousePosition, positionButtonX, positionButtonRulesY, heightButton, widthButton))
		{
			currentScreen = Screen::Rules;
		}
		else if (CheckCollisionMouseButton(MousePosition, positionButtonX, positionButtonCreditsY, heightButton, widthButton))
		{
			currentScreen = Screen::Credits;
		}
		else if (CheckCollisionMouseButton(MousePosition, positionButtonX, positionButtonExitY, heightButton, widthButton))
		{
			currentScreen = Screen::Exit;
		}
	}
}

void IsMousePressingBackButton()
{
	Vector2 MousePosition = GetMousePosition();

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		if (CheckCollisionMouseButton(MousePosition, positionBackButtonX, positionBackButtonY, backButtonHeight, backButtonWidth))
		{
			currentScreen = Screen::Menu;
		}
	}
}

void ButtonDrawing(Vector2 MousePosition)
{
	//DIBUJO BOTONES
	DrawRectangle(positionButtonX, positionButtonPlayY, widthButton, heightButton, VIOLET);
	DrawRectangle(positionButtonX, positionButtonCreditsY, widthButton, heightButton, VIOLET);
	DrawRectangle(positionButtonX, positionButtonRulesY, widthButton, heightButton, VIOLET);
	DrawRectangle(positionButtonX, positionButtonExitY, widthButton, heightButton, VIOLET);

	if (CheckCollisionMouseButton(MousePosition, positionButtonX, positionButtonPlayY, heightButton, widthButton))
	{
		DrawRectangle(positionButtonX, positionButtonPlayY, widthButton, heightButton, BLUE);
	}
	else if (CheckCollisionMouseButton(MousePosition, positionButtonX, positionButtonRulesY, heightButton, widthButton))
	{
		DrawRectangle(positionButtonX, positionButtonRulesY, widthButton, heightButton, BLUE);
	}
	else if (CheckCollisionMouseButton(MousePosition, positionButtonX, positionButtonCreditsY, heightButton, widthButton))
	{
		DrawRectangle(positionButtonX, positionButtonCreditsY, widthButton, heightButton, BLUE);
	}
	else if (CheckCollisionMouseButton(MousePosition, positionButtonX, positionButtonExitY, heightButton, widthButton))
	{
		DrawRectangle(positionButtonX, positionButtonExitY, widthButton, heightButton, BLUE);
	}
}

void ButtonText(Vector2 MousePosition)
{
	DrawText(TextFormat("JUGAR"), positionButtonNamePlayX, positionButtonNamePlayY, fontSizeButtonName, BLUE);
	DrawText(TextFormat("REGLAS"), positionButtonNameRulesX, positionButtonNameRulesY, fontSizeButtonName, BLUE);
	DrawText(TextFormat("CREDITOS"), positionButtonNameCreditsX, positionButtonNameCreditsY, fontSizeButtonName, BLUE);
	DrawText(TextFormat("SALIR"), positionButtonNameExitX, positionButtonNameExitY, fontSizeButtonName, BLUE);

	if (CheckCollisionMouseButton(MousePosition, positionButtonX, positionButtonPlayY, heightButton, widthButton))
	{
		DrawText(TextFormat("JUGAR"), positionButtonNamePlayX, positionButtonNamePlayY, fontSizeButtonName, VIOLET);
	}
	else if (CheckCollisionMouseButton(MousePosition, positionButtonX, positionButtonRulesY, heightButton, widthButton))
	{
		DrawText(TextFormat("REGLAS"), positionButtonNameRulesX, positionButtonNameRulesY, fontSizeButtonName, VIOLET);
	}
	else if (CheckCollisionMouseButton(MousePosition, positionButtonX, positionButtonCreditsY, heightButton, widthButton))
	{
		DrawText(TextFormat("CREDITOS"), positionButtonNameCreditsX, positionButtonNameCreditsY, fontSizeButtonName, VIOLET);
	}
	else if (CheckCollisionMouseButton(MousePosition, positionButtonX, positionButtonExitY, heightButton, widthButton))
	{
		DrawText(TextFormat("SALIR"), positionButtonNameExitX, positionButtonNameExitY, fontSizeButtonName, VIOLET);
	}
}

void BackMenuButton()
{
	Vector2 MousePosition = GetMousePosition();

	DrawRectangle(positionBackButtonX, positionBackButtonY, backButtonWidth, backButtonHeight, VIOLET);

	if (CheckCollisionMouseButton(MousePosition, positionBackButtonX, positionBackButtonY, backButtonHeight, backButtonWidth))
	{
		DrawRectangle(positionBackButtonX, positionBackButtonY, backButtonWidth, backButtonHeight, BLUE);
	}

	DrawText(TextFormat("ATRAS"), 10, 6, 20, BLUE);

	if (CheckCollisionMouseButton(MousePosition, positionBackButtonX, positionBackButtonY, backButtonHeight, backButtonWidth))
	{
		DrawText(TextFormat("ATRAS"), 10, 6, 20, VIOLET);
	}
}

//void Credits()
//{
//	DrawText(TextFormat("THE"), positionGameNameX + 70, positionGameNameY, fontSizeGameName - 30, VIOLET);
//	DrawText(TextFormat("FIRST"), positionGameNameX + 220, positionGameNameY, fontSizeGameName - 30, BLUE);
//	DrawRectangle(363, 95, palletWidth - 5, 35, BLACK);
//
//	DrawText(TextFormat("Creado por:"), positionTextX + 35, 150, 20, VIOLET);
//	DrawText(TextFormat("Mercedes Ramirez Diaz"), positionTextX - 15, 180, 20, BLACK);
//	DrawText(TextFormat("Materia:"), positionTextX + 55, 210, 20, VIOLET);
//	DrawText(TextFormat("Practica Profesional I: Desarrollo de Videojuegos I"), positionTextX - 170, 240, 20, BLACK);
//	DrawText(TextFormat("Profesores:"), positionTextX + 35, 270, 20, VIOLET);
//	DrawText(TextFormat("Stefano Juan Cvitanich"), positionTextX - 15, 300, 20, BLACK);
//	DrawText(TextFormat("Sergio Baretto"), positionTextX + 20, 330, 20, BLACK);
//	DrawText(TextFormat("Adscriptos:"), positionTextX + 35, 360, 20, VIOLET);
//	DrawText(TextFormat("Lucio Stefano Piccioni"), positionTextX - 15, 390, 20, BLACK);
//	DrawText(TextFormat("Sofia Belen Alvarez Franze"), positionTextX - 45, 420, 20, BLACK);
//	DrawText(TextFormat("Institucion:"), positionTextX + 40, 450, 20, VIOLET);
//	DrawText(TextFormat("Image Campus"), positionTextX + 25, 480, 20, BLACK);
//	DrawText(TextFormat("Gracias especiales:"), positionTextX + 2, 510, 20, BLUE);
//	DrawText(TextFormat("Catalina Ramirez Diaz"), positionTextX - 8, 540, 20, BLACK);
//}
//
//void Rules()
//{
//	DrawText(TextFormat("Reglas del PONG"), 40, 60, fontSizeGameName - 45, VIOLET);
//	DrawText(TextFormat("- El objetivo es evitar que la pelota pase tu paleta y lograr\n que pase la del rival."), 50, 100, 20, BLACK);
//	DrawText(TextFormat("- La pelota rebota contra las paredes superior e inferior\n de la pantalla."), 50, 150, 20, BLACK);
//	DrawText(TextFormat("- Cuando la pelota toca una paleta, rebota y cambia de direccion."), 50, 200, 20, BLACK);
//	DrawText(TextFormat("- Si la pelota pasa la paleta de un jugador, el rival gana un punto."), 50, 230, 20, BLACK);
//
//	DrawText(TextFormat("Controles"), 40, 290, fontSizeGameName - 45, VIOLET);
//	DrawText(TextFormat("JUGADOR 1:"), 50, 340, 20, BLUE);
//	DrawText(TextFormat("- W -> Mueve la paleta hacia arriba."), 50, 370, 20, BLACK);
//	DrawText(TextFormat("- S -> Mueve la paleta hacia abajo."), 50, 400, 20, BLACK);
//	DrawText(TextFormat("JUGADOR 2:"), 50, 450, 20, BLUE);
//	DrawText(TextFormat("- Flecha hacia arriba -> Mueve la paleta hacia arriba."), 50, 480, 20, BLACK);
//	DrawText(TextFormat("- Flecha hacia abajo -> Mueve la paleta hacia abajo."), 50, 510, 20, BLACK);
//
//	DrawText(TextFormat("- P -> Pausea el Gameplay."), 50, 550, 20, BLACK);
//}

