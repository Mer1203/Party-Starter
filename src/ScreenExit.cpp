#include "ScreenExit.h"
#include "GameManager.h"

namespace Asteroids
{
	void ExitUpdate(bool& gameIsRunning)
	{
		if (currentScreen == Screen::Exit)
		{
			gameIsRunning = false;
		}
	}
}