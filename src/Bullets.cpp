#include "Bullets.h"
#include "raylib.h"
#include "raymath.h"
#include "Player.h"
#include "Game.h"

Bullets bullets[MAX_BULLETS];

void BulletsInit(Bullets& currentBullet)
{
	currentBullet.position.x = 0.0f;
	currentBullet.position.y = 0.0f;

	currentBullet.direction.x = 0.0f;
	currentBullet.direction.y = 0.0f;

	currentBullet.radius = MAX_BULLET_RADIUS;
	currentBullet.isActive = false;

	currentBullet.speed = MAX_BULLET_SPEED;
	currentBullet.countTime = 0.0f;
	currentBullet.maxTime = MAX_TIME;
}

void SetDirection(Bullets& bullet, Vector2 direction)
{
	bullet.direction = Vector2Normalize(direction);
}

void SetPosition(Bullets& bullet, Vector2 position)
{
	bullet.position = position;
}

void BulletsUpdate(Bullets& currentBullet, float delta)
{
	if (currentBullet.isActive == true)
	{
		currentBullet.position.x += currentBullet.direction.x * currentBullet.speed * delta;
		currentBullet.position.y += currentBullet.direction.y * currentBullet.speed * delta;

		//Esto va actualizando el contador cuando llegue al tiempo maximo, y reinicia los valores de la bala actual:
		currentBullet.countTime += delta;

		if (currentBullet.countTime >= currentBullet.maxTime)
		{
			BulletsInit(currentBullet);
		}

		if (currentBullet.position.x > WINDOW_WIDTH)
		{
			currentBullet.position.x = 0;
		}
		else if (currentBullet.position.x < 0)
		{
			currentBullet.position.x = WINDOW_WIDTH;
		}

		if (currentBullet.position.y > WINDOW_HEIGHT)
		{
			currentBullet.position.y = 0;
		}
		else if (currentBullet.position.y < 0)
		{
			currentBullet.position.y = WINDOW_HEIGHT;
		}

	}
}

void ShotBullet(float delta)
{
	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
	{
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (bullets[i].isActive == false)
			{
				bullets[i].isActive = true;

				SetDirection(bullets[i], player.direction);
				SetPosition(bullets[i], player.position);

				break;
			}
		}
	}
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		BulletsUpdate(bullets[i], delta);
	}
}

void BulletsDraw()
{
#ifdef _DEBUG
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (bullets[i].isActive == true)
		{
			DrawCircleV(bullets[i].position, bullets[i].radius, GREEN);
		}
	}
#endif
}