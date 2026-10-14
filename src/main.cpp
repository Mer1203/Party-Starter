#include "raylib.h"

int main()
{
	const int WINDOW_WIDTH = 1024;
	const int WINDOW_HEIGHT = 768;

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Party Starter!");

	float posX = 320.0f;
	int posY = 225;
	int radio = 100;

	// Loop
	while (!WindowShouldClose())
	{
		// Chequeo de Input

		if (IsKeyDown(KEY_UP))
			posY--;

		if (IsKeyDown(KEY_DOWN))
			posY++;

		if (IsKeyDown(KEY_LEFT))
			posX--;

		if (IsKeyDown(KEY_RIGHT))
			posX++;


		// Actualización

		// Dibujado
		BeginDrawing();
		ClearBackground(WHITE); // system("cls");

		DrawCircle(posX, posY, radio, BLUE);

		EndDrawing();
	}

	// Cierre
	CloseWindow();
}



//#include "raylib.h"
//
//int main()
//{
//    const int WINDOW_WIDTH = 1024;
//    const int WINDOW_HEIGHT = 768;
//
//    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Party Starter!");
//
//    // Loop
//    while (!WindowShouldClose())
//    {
//        // Dibujado
//        BeginDrawing();
//        ClearBackground(WHITE); // system("cls");
//
//        DrawRectangle(50,50,50,50, RED);
//
//        EndDrawing();
//    }
//
//    CloseWindow();
//}