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


	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		//Vector direccion:
		player.direction = Vector2Subtract(GetMousePosition(), player.position);

		player.direction.x = GetMouseX() - player.position.x;
		player.direction.y = GetMouseY() - player.position.y;

		Vector2 dirNormalizado = Vector2Normalize(player.direction);
	
		player.speed.x += dirNormalizado.x * delta * MAX_SPEED;
		player.speed.y += dirNormalizado.y * delta * MAX_SPEED;

		if (Vector2Length(player.speed) > MAX_SPEED)
		{
			player.speed.x = (player.speed.x / Vector2Length(player.speed)) * MAX_SPEED;
			player.speed.y = (player.speed.y / Vector2Length(player.speed)) * MAX_SPEED;
		}
	}

	player.position.x += player.speed.x * delta;
	player.position.y += player.speed.y * delta;

	if (player.position.x > WINDOW_WIDTH)
	{
		player.position.x = 0;
	}
	else if (player.position.x < 0)
	{
		player.position.x = WINDOW_WIDTH;
	}

	if (player.position.y > WINDOW_HEIGHT)
	{
		player.position.y = 0;
	}
	else if (player.position.y < 0)
	{
		player.position.y = WINDOW_HEIGHT;
	}

}

void PlayerDraw()
{
	DrawCircleV(player.position, player.radius, GREEN);
}