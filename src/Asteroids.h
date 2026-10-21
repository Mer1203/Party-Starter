#pragma once
#include "raylib.h"

namespace Asteroids
{
	struct Asteroids
	{
		Vector2 position;
		Vector2 direction;
		float speed;
		float radius;
		bool isDestroyed;
	};

	const int MAX_ASTEROIDS = 30;

	extern Asteroids bigAsteroid[MAX_ASTEROIDS];
	extern Asteroids middleAsteroid[MAX_ASTEROIDS];
	extern Asteroids smallAsteroid[MAX_ASTEROIDS];

	const int MAX_BIG_ASTEROID_SPEED = 300;
	const int MAX_MIDDLE_ASTEROID_SPEED = 200;
	const int MAX_SMALL_ASTEROID_SPEED = 100;

	void AsteroidsInit(Asteroids currentBigAsteroid, Asteroids currentMiddleAsteroid, Asteroids currentSmallAsteroid);
	void AsteroidsUpdate(Asteroids currentAsteroid, float delta);

	void CreateAsteroid(Asteroids currentAsteroid);

	void AsteroidOneDraw(Asteroids currentAsteroid);
	void AsteroidTwoDraw(Asteroids currentAsteroid);
	void AsteroidThreeDraw(Asteroids currentAsteroid);
}