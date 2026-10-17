#include "Player.h"
#include "Game.h"
#include "raylib.h"
#include "raymath.h"

Player player;

void PlayerInit()
{
	player.position.x = WINDOW_WIDTH / 2;
	player.position.y = WINDOW_HEIGHT / 2;
	player.direction.x = 0;
	player.direction.y = 0;
	player.isAlive = true;
	player.radius = 50;
}

void PlayerUpdate(float delta)
{
	Vector2 mousePosition = GetMousePosition();


	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		//Vector direccion:
		player.direction = Vector2Subtract(GetMousePosition(), player.position);

		player.direction.x = GetMouseX() - player.position.x;
		player.direction.y = GetMouseY() - player.position.y;

		Vector2 dirNormalizado = Vector2Normalize(player.direction);

		player.position.x += dirNormalizado.x * GetFrameTime() * delta;
		player.position.y += dirNormalizado.y * GetFrameTime() * delta;
	}
}

void PlayerDraw()
{
	DrawCircleV(player.position, player.radius, GREEN);
}