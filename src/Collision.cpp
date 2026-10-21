#include "Collision.h"
#include "raylib.h"
#include "raymath.h"
#include "Player.h"

namespace Asteroids
{
	bool CollisionCircleCircle(float circleOneX, float circleOneY, float circleOneRadious,
		float circleTwoX, float circleTwoY, float circleTwoRadious)
	{
		float distanceX = 0.0f;
		float distanceY = 0.0f;
		float distance = 0.0f;

		distanceX = circleOneX - circleTwoX;
		distanceY = circleOneY - circleTwoY;

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