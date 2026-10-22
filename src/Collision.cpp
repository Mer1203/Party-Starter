#include "Collision.h"
#include "raylib.h"
#include "raymath.h"
#include "Player.h"

namespace Asteroids
{
	bool CollisionCircleCircle(Vector2 circleOne, float circleOneRadious, Vector2 circleTwo, float circleTwoRadious)
	{
		float distanceX = 0.0f;
		float distanceY = 0.0f;
		float distance = 0.0f;

		distanceX = circleOne.x - circleTwo.x;
		distanceY = circleOne.y - circleTwo.y;

		distance = static_cast<float>(sqrt((distanceX * distanceX) + (distanceY * distanceY)));

		if (distance <= (circleOneRadious + circleTwoRadious))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}