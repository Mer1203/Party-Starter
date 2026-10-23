#include "Button.h"
#include "raylib.h"

namespace Asteroids
{
	Button play;
	Button rules;
	Button credits;
	Button exitGame;
	Button back;
	Button pause;
	Button fontLink;
	Button soundOneLink;
	Button soundTwoLink;

	void ButtonInit()
	{
		play.isPressed = false;
		play.position.x = 700;
		play.position.y = 180;
		play.textPosition.x = 780;
		play.textPosition.y = 197;
		play.textSize = 40;
		play.size.y = 80; //height
		play.size.x = 280; //width
		play.fontSize = 60;
		play.spacing = 2;

		rules.isPressed = false;
		rules.position.x = 700;
		rules.position.y = 310;
		rules.textPosition.x = 775;
		rules.textPosition.y = 327;
		rules.textSize = 40;
		rules.size.y = 80;
		rules.size.x = 280;
		rules.fontSize = 60;
		rules.spacing = 2;

		credits.isPressed = false;
		credits.position.x = 700;
		credits.position.y = 440;
		credits.textPosition.x = 755;
		credits.textPosition.y = 456;
		credits.textSize = 40;
		credits.size.y = 80;
		credits.size.x = 280;
		credits.fontSize = 60;
		credits.spacing = 2;

		exitGame.isPressed = false;
		exitGame.position.x = 700;
		exitGame.position.y = 570;
		exitGame.textPosition.x = 800;
		exitGame.textPosition.y = 587;
		exitGame.textSize = 40;
		exitGame.size.y = 80;
		exitGame.size.x = 280;
		exitGame.fontSize = 60;
		exitGame.spacing = 2;

		back.position.x = 0;
		back.position.y = 0;
		back.size.y = 70;
		back.size.x = 70;
		back.textPosition.x = -40;
		back.textPosition.y = -20;
		back.textSize = 20;
		back.fontSize = 30;
		back.spacing = 2;

		pause.position.x = 0;
		pause.position.y = 0;
		pause.size.y = 70;
		pause.size.x = 70;
		pause.textPosition.x = -40;
		pause.textPosition.y = -20;
		pause.textSize = 20;
		pause.fontSize = 30;
		pause.spacing = 2;

		fontLink.position.x = 452;
		fontLink.position.y = 382;
		fontLink.size.y = 34;
		fontLink.size.x = 120;

		soundOneLink.position.x = 452;
		soundOneLink.position.y = 532;
		soundOneLink.size.y = 34;
		soundOneLink.size.x = 120;

		soundTwoLink.position.x = 452;
		soundTwoLink.position.y = 632;
		soundTwoLink.size.y = 34;
		soundTwoLink.size.x = 120;
	}

	bool CheckCollisionMouseButton(Vector2 mousePosition, float buttonX, float buttonY, float buttonHeight, float buttonWidth)
	{
		return buttonX <= mousePosition.x && buttonX + buttonWidth >= mousePosition.x
			&& mousePosition.y >= buttonY && mousePosition.y <= buttonY + buttonHeight;
	}

	void IsMousePressed(Sound menuButtonsSound)
	{
		Vector2 mousePosition = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (CheckCollisionMouseButton(mousePosition, play.position.x, play.position.y, play.size.y, play.size.x))
			{
				currentScreen = Screen::Play;

				if (!IsSoundPlaying(menuButtonsSound))
				{
					PlaySound(menuButtonsSound);
				}
			}
			else if (CheckCollisionMouseButton(mousePosition, rules.position.x, rules.position.y, rules.size.y, rules.size.x))
			{
				currentScreen = Screen::Rules;

				if (!IsSoundPlaying(menuButtonsSound))
				{
					PlaySound(menuButtonsSound);
				}
			}
			else if (CheckCollisionMouseButton(mousePosition, credits.position.x, credits.position.y, credits.size.y, credits.size.x))
			{
				currentScreen = Screen::Credits;

				if (!IsSoundPlaying(menuButtonsSound))
				{
					PlaySound(menuButtonsSound);
				}
			}
			else if (CheckCollisionMouseButton(mousePosition, exitGame.position.x, exitGame.position.y, exitGame.size.y, exitGame.size.x))
			{
				currentScreen = Screen::Exit;

				if (!IsSoundPlaying(menuButtonsSound))
				{
					PlaySound(menuButtonsSound);
				}
			}
		}
	}

	void IsMousePressingBackButton()
	{
		Vector2 mousePosition = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (CheckCollisionMouseButton(mousePosition, back.position.x, back.position.y, back.size.y, back.size.x))
			{
				currentScreen = Screen::Menu;
			}
		}
	}

	void IsMousePressingPauseButton()
	{
		Vector2 mousePosition = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (CheckCollisionMouseButton(mousePosition, pause.position.x, pause.position.y, pause.size.y, pause.size.x))
			{
				currentScreen = Screen::Pause;
			}
		}
	}

	void IsMousePressingLinkButtons()
	{
		Vector2 mousePosition = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (CheckCollisionMouseButton(mousePosition, fontLink.position.x, fontLink.position.y, fontLink.size.y, fontLink.size.x))
			{
				OpenURL("https://www.dafont.com/es/super-wonder.font");
			}
			else if (CheckCollisionMouseButton(mousePosition, soundOneLink.position.x, soundOneLink.position.y, soundOneLink.size.y, soundOneLink.size.x))
			{
				OpenURL("https://www.myinstants.com/es/instant/confetti-pop-39104/?utm_source=copy&utm_medium=share");
			}
			else if (CheckCollisionMouseButton(mousePosition, soundTwoLink.position.x, soundTwoLink.position.y, soundTwoLink.size.y, soundTwoLink.size.x))
			{
				OpenURL("https://www.myinstants.com/es/instant/meme-camioneta-payaso-23037/?utm_source=copy&utm_medium=share");
			}
		}
	}

	void LinkButtonDraw(Vector2 mousePosition, Texture2D linkButton, Texture2D linkButtonPressed)
	{
		//El boton original mide 280x80, se achica para que quede de 120x34
		float linkScale = 0.43f;

#ifdef _DEBUG
		DrawRectangleV(fontLink.position, fontLink.size, VIOLET);
		DrawRectangleV(soundOneLink.position, soundOneLink.size, VIOLET);
		DrawRectangleV(soundTwoLink.position, soundTwoLink.size, VIOLET);
#endif

		DrawTextureEx(linkButton, fontLink.position, 0, linkScale, WHITE);
		DrawTextureEx(linkButton, soundOneLink.position, 0, linkScale, WHITE);
		DrawTextureEx(linkButton, soundTwoLink.position, 0, linkScale, WHITE);

		if (CheckCollisionMouseButton(mousePosition, fontLink.position.x, fontLink.position.y, fontLink.size.y, fontLink.size.x))
		{
			DrawTextureEx(linkButtonPressed, fontLink.position, 0, linkScale, WHITE);
		}
		else if (CheckCollisionMouseButton(mousePosition, soundOneLink.position.x, soundOneLink.position.y, soundOneLink.size.y, soundOneLink.size.x))
		{
			DrawTextureEx(linkButtonPressed, soundOneLink.position, 0, linkScale, WHITE);
		}
		else if (CheckCollisionMouseButton(mousePosition, soundTwoLink.position.x, soundTwoLink.position.y, soundTwoLink.size.y, soundTwoLink.size.x))
		{
			DrawTextureEx(linkButtonPressed, soundTwoLink.position, 0, linkScale, WHITE);
		}
	}

	void ButtonDraw(Vector2 mousePosition, Texture2D playButton, Texture2D rulesButton, Texture2D creditsButton,
		Texture2D exitButton, Texture2D playPressedButton, Texture2D rulesPressedButton, Texture2D creditsPressedButton,
		Texture2D exitPressedButton)
	{
		//DIBUJO BOTONES
#ifdef _DEBUG
		DrawRectangleV(play.position, play.size, VIOLET);
		DrawRectangleV(rules.position, rules.size, VIOLET);
		DrawRectangleV(credits.position, credits.size, VIOLET);
		DrawRectangleV(exitGame.position, exitGame.size, VIOLET);
#endif

		DrawTextureEx(playButton, play.position, 0, 1, WHITE);
		DrawTextureEx(rulesButton, rules.position, 0, 1, WHITE);
		DrawTextureEx(creditsButton, credits.position, 0, 1, WHITE);
		DrawTextureEx(exitButton, exitGame.position, 0, 1, WHITE);


		if (CheckCollisionMouseButton(mousePosition, play.position.x, play.position.y, play.size.y, play.size.x))
		{
#ifdef _DEBUG
			DrawRectangleV(play.position, play.size, BLUE);
#endif
			DrawTextureEx(playPressedButton, play.position, 0, 1, WHITE);
		}
		else if (CheckCollisionMouseButton(mousePosition, rules.position.x, rules.position.y, rules.size.y, rules.size.x))
		{
#ifdef _DEBUG
			DrawRectangleV(rules.position, rules.size, BLUE);
#endif
			DrawTextureEx(rulesPressedButton, rules.position, 0, 1, WHITE);
		}
		else if (CheckCollisionMouseButton(mousePosition, credits.position.x, credits.position.y, credits.size.y, credits.size.x))
		{
#ifdef _DEBUG
			DrawRectangleV(credits.position, credits.size, BLUE);
#endif
			DrawTextureEx(creditsPressedButton, credits.position, 0, 1, WHITE);
		}
		else if (CheckCollisionMouseButton(mousePosition, exitGame.position.x, exitGame.position.y, exitGame.size.y, exitGame.size.x))
		{
#ifdef _DEBUG
			DrawRectangleV(exitGame.position, exitGame.size, BLUE);
#endif
			DrawTextureEx(exitPressedButton, exitGame.position, 0, 1, WHITE);
		}
	}

	void ButtonTextDraw(Font font)
	{
		DrawTextEx(font, "PLAY", play.textPosition, play.fontSize, play.spacing, WHITE);
		DrawTextEx(font, "RULES", rules.textPosition, rules.fontSize, rules.spacing, WHITE);
		DrawTextEx(font, "CREDITS", credits.textPosition, credits.fontSize, credits.spacing, WHITE);
		DrawTextEx(font, "EXIT", exitGame.textPosition, exitGame.fontSize, exitGame.spacing, WHITE);
	}

	void BackButton(Texture2D backButton, Texture2D backButtonPressed)
	{
		Vector2 mousePosition = GetMousePosition();
#ifdef _DEBUG
		DrawRectangleV(back.position, back.size, VIOLET);
#endif
		DrawTextureEx(backButton, back.textPosition, 0, 0.07f, WHITE);

		if (CheckCollisionMouseButton(mousePosition, back.position.x, back.position.y, back.size.y, back.size.x))
		{
#ifdef _DEBUG
			DrawRectangleV(back.position, back.size, BLUE);
#endif
			DrawTextureEx(backButtonPressed, back.textPosition, 0, 0.07f, WHITE);
		}
	}

	void PauseButton(Texture2D pauseButton, Texture2D pauseButtonPressed)
	{
		Vector2 mousePosition = GetMousePosition();
#ifdef _DEBUG
		DrawRectangleV(pause.position, pause.size, VIOLET);
#endif
		DrawTextureEx(pauseButton, pause.textPosition, 0, 0.07f, WHITE);

		if (CheckCollisionMouseButton(mousePosition, pause.position.x, pause.position.y, pause.size.y, pause.size.x))
		{
#ifdef _DEBUG
			DrawRectangleV(pause.position, pause.size, BLUE);
#endif
			DrawTextureEx(pauseButtonPressed, pause.textPosition, 0, 0.07f, WHITE);
		}
	}

}