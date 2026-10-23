#include "GameManager.h"
#include "ScreenGameOver.h"
#include "ScreenCredits.h"
#include "ScreenRules.h"
#include "ScreenPause.h"
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
			//Inicio los valores de todos los botones:
			ButtonInit();
			PauseInit();
			GameOverInit();
			IsMousePressed();
			MenuInit();

			GameplayInit();
			PlayerInit(canion);
			AsteroidsInitAll();
			for (int i = 0; i < MAX_BULLETS; i++)
			{
				BulletsInit(bullets[i]);
			}
			GetMousePosition();
			break;
		case Screen::Play:
			PlayerUpdate(delta);
			ShotBullet(delta);
			AsteroidsUpdate(delta);
			IsMousePressingPauseButton();

			for (int i = 0; i < MAX_ASTEROIDS; i++)
			{
				PlayerGameOver(bigAsteroid[i]);
			}

			for (int i = 0; i < MAX_ASTEROIDS; i++)
			{
				PlayerGameOver(middleAsteroid[i]);
			}

			for (int i = 0; i < MAX_ASTEROIDS; i++)
			{
				PlayerGameOver(smallAsteroid[i]);
			}

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
		case Screen::GameOver:
			GameOverUpdate(canion);
			break;
		case Screen::Pause:
			PauseUpdate();
			break;
		default:
			break;
		}
	}

	void Draw(Texture2D backgroundMenu, Texture2D backgroundGameplay, Texture2D canion,
		Texture2D confetti, Texture2D playButton, Texture2D rulesButton, Texture2D creditsButton,
		Texture2D exitButton, Texture2D playPressedButton, Texture2D rulesPressedButton,
		Texture2D creditsPressedButton, Texture2D exitPressedButton, Font font, Texture2D piñataOne, 
		Texture2D piñataTwo,Texture2D piñataThree, Texture2D backButton, Texture2D backButtonPressed,
		Texture2D pauseButton, Texture2D pauseButtonPressed, Texture2D pauseButtonScreen,
		Texture2D pauseButtonScreenPressed)
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
			GameplayDraw(backgroundGameplay, canion, confetti, piñataOne, piñataTwo, piñataThree, font);
			PauseButton(pauseButton, pauseButtonPressed);
			break;
		case Screen::Rules:
			RulesDraw(backgroundGameplay);
			BackButton(backButton, backButtonPressed);
			break;
		case Screen::Credits:
			CreditsDraw(backgroundGameplay);
			BackButton(backButton, backButtonPressed);
			break;
		case Screen::Exit:
			break;
		case Screen::GameOver:
			GameOverDraw(backgroundGameplay, canion, confetti,
				piñataOne, piñataTwo, piñataThree, font, pauseButtonScreen,
				pauseButtonScreenPressed);
			break;
		case Screen::Pause:
			PauseDraw(backgroundGameplay, canion, confetti,
				piñataOne, piñataTwo, piñataThree, font, pauseButtonScreen,
				pauseButtonScreenPressed);
			break;
		default:
			break;
		}

		EndDrawing();
	}
}