#include "Asteroids.h"
#include "raylib.h"
#include "raymath.h"
#include <ctime>
#include <cstdlib>

namespace Asteroids
{
	Asteroids bigAsteroid[MAX_ASTEROIDS];
	Asteroids middleAsteroid[MAX_ASTEROIDS];
	Asteroids smallAsteroid[MAX_ASTEROIDS];

	void AsteroidsInit()
	{
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			bigAsteroid[i].position.x = 0;
			bigAsteroid[i].position.y = 0;
			bigAsteroid[i].direction.x = 0;
			bigAsteroid[i].direction.y = 0;
			bigAsteroid[i].radius = 40;
			bigAsteroid[i].isDestroyed = false;
		}

		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			middleAsteroid[i].position.x = 0;
			middleAsteroid[i].position.y = 0;
			middleAsteroid[i].direction.x = 0;
			middleAsteroid[i].direction.y = 0;
			middleAsteroid[i].radius = 25;
			middleAsteroid[i].isDestroyed = false;
		}

		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			smallAsteroid[i].position.x = 0;
			smallAsteroid[i].position.y = 0;
			smallAsteroid[i].direction.x = 0;
			smallAsteroid[i].direction.y = 0;
			smallAsteroid[i].radius = 10;
			smallAsteroid[i].isDestroyed = false;
		}
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
