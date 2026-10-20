#include "Player.h"
#include "Game.h"
#include "raylib.h"
#include "raymath.h"

Player player;
Rectangle rectangle;

void PlayerInit()
{
	player.position.x = WINDOW_WIDTH / 2;
	player.position.y = WINDOW_HEIGHT / 2;
	player.direction.x = 0;
	player.direction.y = 0;
	player.isAlive = true;
	player.radius = 50;
	player.height = 100;
	player.width = 100;
	player.rotation = 0.0f;

	rectangle.x = player.position.x;
	rectangle.y = player.position.y;
	rectangle.width = 100;
	rectangle.height = 100;
}

void PlayerUpdate(float delta)
{
	Vector2 mousePosition = GetMousePosition();
	double angle = 0.0f;

	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		//Vector direccion:
		player.direction = Vector2Subtract(GetMousePosition(), player.position);

		Vector2 dirNormalizado = Vector2Normalize(player.direction);
	
		player.speed.x += dirNormalizado.x * delta * MAX_PLAYER_SPEED;
		player.speed.y += dirNormalizado.y * delta * MAX_PLAYER_SPEED;

		if (Vector2Length(player.speed) > MAX_PLAYER_SPEED)
		{
			player.speed.x = (player.speed.x / Vector2Length(player.speed)) * MAX_PLAYER_SPEED;
			player.speed.y = (player.speed.y / Vector2Length(player.speed)) * MAX_PLAYER_SPEED;
		}

		angle = atan(static_cast<double>(player.direction.y / player.direction.x));
		//paso el angulo de radianes a grados:
		angle *= RAD2DEG;

		if (player.position.x < mousePosition.x && player.position.y > mousePosition.y)
		{
			angle += 0;
		}
		else if (player.position.x > mousePosition.x && player.position.y > mousePosition.y)
		{
			angle += 180;
		}
		else if (player.position.x > mousePosition.x && player.position.y < mousePosition.y)
		{
			angle += 180;
		}
		else if (player.position.x < mousePosition.x && player.position.y < mousePosition.y)
		{
			angle += 360;
		}

		player.rotation = static_cast<float>(angle);
	}

	player.position.x += player.speed.x * delta;
	player.position.y += player.speed.y * delta;

	rectangle.x = player.position.x;
	rectangle.y = player.position.y;

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
	DrawRectanglePro(rectangle, {rectangle.width / 2, rectangle.height / 2}, player.rotation, BLUE);
	DrawCircleV(player.position, player.radius, GREEN);
}