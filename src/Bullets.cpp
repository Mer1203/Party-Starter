#include "Bullets.h"
#include "raylib.h"
#include "raymath.h"

Bullets bullets[MAX_BULLETS];

void BulletsInit()
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		bullets[i].position.x = 0.0f;
		bullets[i].position.y = 0.0f;

		bullets[i].direction.x = 0.0f;
		bullets[i].direction.y = 0.0f;
	
		bullets[i].radius = MAX_BULLET_RADIUS;
		bullets[i].isActive = false;

		bullets[i].speed = MAX_SPEED;
		bullets[i].countTime = 0.0f;
		bullets[i].maxTime = MAX_TIME;
	}
}

void SetDirection(Bullets& bullet, Vector2 direction)
{
	bullet.direction = Vector2Normalize(direction);
}

void SetPosition(Bullets& bullet, Vector2 position)
{
	bullet.position = position;
}

void BulletsUpdate()
{

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