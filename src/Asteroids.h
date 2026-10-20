#pragma once
#include "raylib.h"

struct Asteroids
{
	Vector2 position;
	Vector2 direction;
	float speed;
	float radius;
	bool isDestroyed;
};

const int MAX_ASTEROIDS = 30;

extern Asteroids asteroidOne[MAX_ASTEROIDS];
extern Asteroids asteroidTwo[MAX_ASTEROIDS];
extern Asteroids asteroidThree[MAX_ASTEROIDS];

const int MAX_SPEED = 400;

void AsteroidsInit();
void AsteroidsUpdate(Asteroids currentAsteroid, float delta);

void CreateAsteroid(Asteroids currentAsteroid);

void AsteroidOneDraw(Asteroids currentAsteroid);
void AsteroidTwoDraw(Asteroids currentAsteroid);
void AsteroidThreeDraw(Asteroids currentAsteroid);
