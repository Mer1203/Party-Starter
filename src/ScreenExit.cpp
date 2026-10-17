#include "ScreenExit.h"
#include "GameManager.h"

void ExitUpdate(bool& gameIsRunning)
{
	if (currentScreen == Screen::Exit)
	{
		gameIsRunning = false;
	}
}