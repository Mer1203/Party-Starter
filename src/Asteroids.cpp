#include "Asteroids.h"
#include "raylib.h"
#include "raymath.h"
#include <ctime>
#include <cstdlib>

Asteroids asteroidOne[MAX_ASTEROIDS];
Asteroids asteroidTwo[MAX_ASTEROIDS];
Asteroids asteroidThree[MAX_ASTEROIDS];

void AsteroidsInit()
{
	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		asteroidOne[i].position.x = 0;
		asteroidOne[i].position.y = 0;
		asteroidOne[i].direction.x = 0;
		asteroidOne[i].direction.y = 0;
		asteroidOne[i].radius = 40;
		asteroidOne[i].isDestroyed = false;
	}

	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		asteroidTwo[i].position.x = 0;
		asteroidTwo[i].position.y = 0;
		asteroidTwo[i].direction.x = 0;
		asteroidTwo[i].direction.y = 0;
		asteroidTwo[i].radius = 25;
		asteroidTwo[i].isDestroyed = false;
	}

	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		asteroidThree[i].position.x = 0;
		asteroidThree[i].position.y = 0;
		asteroidThree[i].direction.x = 0;
		asteroidThree[i].direction.y = 0;
		asteroidThree[i].radius = 10;
		asteroidThree[i].isDestroyed = false;
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
		if (bool CollisionCircleCircle(currentAsteroid.position.x, currentAsteroid.position.y, currentAsteroid.radious,
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
