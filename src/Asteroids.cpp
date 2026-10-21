#include "Asteroids.h"
#include "raymath.h"
#include "raylib.h"
#include "Game.h"
#include <ctime>
#include <cstdlib>

namespace Asteroids
{
	Asteroids bigAsteroid[MAX_ASTEROIDS];
	Asteroids middleAsteroid[MAX_ASTEROIDS];
	Asteroids smallAsteroid[MAX_ASTEROIDS];

	void AsteroidsInit(Asteroids currentBigAsteroid, Asteroids currentMiddleAsteroid, Asteroids currentSmallAsteroid)
	{
		currentBigAsteroid.position.x = 0;
		currentBigAsteroid.position.y = 0;
		currentBigAsteroid.direction.x = 0;
		currentBigAsteroid.direction.y = 0;
		currentBigAsteroid.speed = MAX_BIG_ASTEROID_SPEED;
		currentBigAsteroid.radius = 40;
		currentBigAsteroid.isDestroyed = false;

		currentMiddleAsteroid.position.x = 0;
		currentMiddleAsteroid.position.y = 0;
		currentMiddleAsteroid.direction.x = 0;
		currentMiddleAsteroid.direction.y = 0;
		currentMiddleAsteroid.speed = MAX_MIDDLE_ASTEROID_SPEED;
		currentMiddleAsteroid.radius = 25;
		currentMiddleAsteroid.isDestroyed = false;

		currentSmallAsteroid.position.x = 0;
		currentSmallAsteroid.position.y = 0;
		currentSmallAsteroid.direction.x = 0;
		currentSmallAsteroid.direction.y = 0;
		currentSmallAsteroid.speed = MAX_SMALL_ASTEROID_SPEED;
		currentSmallAsteroid.radius = 10;
		currentSmallAsteroid.isDestroyed = false;
	}

	void CreateAsteroid(Asteroids currentAsteroid)
	{
		int randomDirection = 0;
		//Dandole una direccion random:

		randomDirection = rand() % (1 - (-1) + 1);
		currentAsteroid.direction.x = static_cast<float>(randomDirection);
		randomDirection = rand() % (1 - (-1) + 1);
		currentAsteroid.direction.y = static_cast<float>(randomDirection);
	}

	void AsteroidsUpdate(Asteroids currentAsteroid, float delta)
	{
		//seteo la direccion en la q van a ir;
		currentAsteroid.position.x += currentAsteroid.direction.x * currentAsteroid.speed * delta;
		currentAsteroid.position.y += currentAsteroid.direction.y * currentAsteroid.speed * delta;

		/*
			if (CollisionCircleCircle(currentAsteroid.position.x, currentAsteroid.position.y, currentAsteroid.radious,
							   float circleTwoX, float circleTwoY, float circleTwoRadious))
			{
				isDestroyed = true;
			}

			if (isDestroyed == false)
			{
				AsteroidOneDraw() // cualquiera de los 3 dibujos de los asteroides
			}
			else
			{
				que se arranquen a dibujar dos mas chicos;
			}
		*/

		if (currentAsteroid.position.x > WINDOW_WIDTH)
		{
			currentAsteroid.position.x = 0;
		}
		else if (currentAsteroid.position.x < 0)
		{
			currentAsteroid.position.x = WINDOW_WIDTH;
		}

		if (currentAsteroid.position.y > WINDOW_HEIGHT)
		{
			currentAsteroid.position.y = 0;
		}
		else if (currentAsteroid.position.y < 0)
		{
			currentAsteroid.position.y = WINDOW_HEIGHT;
		}
	}

	void AsteroidOneDraw(Asteroids currentAsteroid)
	{
#ifdef _DEBUG
		DrawCircleV(currentAsteroid.position, currentAsteroid.radius, GREEN);
#endif 
	}

	void AsteroidTwoDraw(Asteroids currentAsteroid)
	{
#ifdef _DEBUG
		DrawCircleV(currentAsteroid.position, currentAsteroid.radius, GREEN);
#endif 
	}

	void AsteroidThreeDraw(Asteroids currentAsteroid)
	{
#ifdef _DEBUG
		DrawCircleV(currentAsteroid.position, currentAsteroid.radius, GREEN);
#endif
	}
}
