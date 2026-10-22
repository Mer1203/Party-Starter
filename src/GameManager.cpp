#include "GameManager.h"
#include "ScreenMenu.h"
#include "ScreenExit.h"
#include "ScreenPlay.h"
#include "Asteroids.h"
#include "Bullets.h"
#include "Player.h"
#include "Button.h"
#include "raylib.h"

namespace Asteroids
{
	Screen currentScreen = Screen::Menu;

	void Update(float delta, bool& gameIsRunning, Texture2D canion)
	{
		// UPDATE:
		switch (currentScreen)
		{
		case Screen::Menu:
			MenuInit();
			//Inicio los valores de todos los botones:
			ButtonInit();
			PlayerInit(canion);
			AsteroidsInitAll();
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
			AsteroidsUpdate(delta);

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

	void Draw(Texture2D backgroundMenu, Texture2D backgroundGameplay, Texture2D canion,
		Texture2D confetti, Texture2D playButton, Texture2D rulesButton, Texture2D creditsButton,
		Texture2D exitButton, Texture2D playPressedButton, Texture2D rulesPressedButton,
		Texture2D creditsPressedButton, Texture2D exitPressedButton, Font font, Texture2D piñataOne, 
		Texture2D piñataTwo,Texture2D piñataThree, Texture2D backButton, Texture2D backButtonPressed)
	{
		//DIBUJADO:
		BeginDrawing();
		ClearBackground(WHITE);

		switch (currentScreen)
		{
		case Screen::Menu:
			MenuDraw(backgroundMenu, playButton, rulesButton, creditsButton, exitButton, 
				playPressedButton, rulesPressedButton, creditsPressedButton, exitPressedButton, font);
			break;
		case Screen::Play:
			GameplayDraw(backgroundGameplay, canion, confetti, piñataOne, piñataTwo, piñataThree);
			//Provisorio, despues cambiar a boton de pausa!
			BackButton(backButton, backButtonPressed);
			break;
		case Screen::Rules:
			BackButton(backButton, backButtonPressed);
			break;
		case Screen::Credits:
			BackButton(backButton, backButtonPressed);
			break;
		case Screen::Exit:
			break;
		default:
			break;
		}

		EndDrawing();
	}
}