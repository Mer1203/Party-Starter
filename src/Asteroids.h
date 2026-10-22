#pragma once
#include "raylib.h"
#include "Bullets.h"
#include <ctime>
#include <cstdlib>

namespace Asteroids
{
	struct Asteroids
	{
		Vector2 position;
		Vector2 direction;
		float speed;
		float radius;
		float countTime;
		float maxTime;
		bool isDestroyed;
	};

	const int MAX_ASTEROIDS = 30;

	const int MAX_BIG_ASTEROID_SPEED = 100;
	const int MAX_MIDDLE_ASTEROID_SPEED = 120;
	const int MAX_SMALL_ASTEROID_SPEED = 140;
	
	extern Asteroids bigAsteroid[MAX_ASTEROIDS];
	extern Asteroids middleAsteroid[MAX_ASTEROIDS];
	extern Asteroids smallAsteroid[MAX_ASTEROIDS];

	void AsteroidsInitAll();
	void BigAsteroidInit(Asteroids& currentBigAsteroid);
	void MiddleAsteroidInit(Asteroids& currentMiddleAsteroid);
	void SmallAsteroidInit(Asteroids& currentSmallAsteroid);

	void SetAsteroidDirection(Asteroids& currentAsteroid);
	void SpawnTimeAsteroids(Asteroids& currentBigAsteroid, float delta);
	
	void SpawnBigAsteroid();
	void SpawnMiddleAsteroid(Vector2 position);
	void SpawnSmallAsteroid(Vector2 position);

	void AsteroidsUpdate(float delta);

	void GoToaSidetoAnother(Asteroids& asteroid);

	void BigAsteroidDraw();
	void MiddleAsteroidDraw();
	void SmallAsteroidDraw();
}