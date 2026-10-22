#include "Asteroids.h"
#include "Collision.h"
#include "Bullets.h"
#include "raymath.h"
#include "Player.h"
#include "Game.h"
#include "raylib.h"
#include <ctime>
#include <cstdlib>

namespace Asteroids
{
	Asteroids bigAsteroid[MAX_ASTEROIDS];
	Asteroids middleAsteroid[MAX_ASTEROIDS];
	Asteroids smallAsteroid[MAX_ASTEROIDS];

	void AsteroidsInitAll()
	{
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			BigAsteroidInit(bigAsteroid[i]);
			MiddleAsteroidInit(middleAsteroid[i]);
			SmallAsteroidInit(smallAsteroid[i]);

			bigAsteroid[i].isDestroyed = true;
			middleAsteroid[i].isDestroyed = true;
			smallAsteroid[i].isDestroyed = true;
		}
	}

	void BigAsteroidInit(Asteroids& currentBigAsteroid)
	{
		float randomSpawnTime = static_cast<float>(rand() % (5 - 2 + 1) + 2);

		currentBigAsteroid.position.x = 0;
		currentBigAsteroid.position.y = 0;
		currentBigAsteroid.direction.x = 0;
		currentBigAsteroid.direction.y = 0;
		currentBigAsteroid.speed = MAX_BIG_ASTEROID_SPEED;
		currentBigAsteroid.countTime = 0.0f;
		currentBigAsteroid.radius = 50;
		currentBigAsteroid.isDestroyed = true;
		currentBigAsteroid.maxTime = randomSpawnTime;
	}

	void MiddleAsteroidInit(Asteroids& currentMiddleAsteroid)
	{
		float randomSpawnTime = static_cast<float>(rand() % (5 - 2 + 1) + 1);

		currentMiddleAsteroid.position.x = 0;
		currentMiddleAsteroid.position.y = 0;
		currentMiddleAsteroid.direction.x = 0;
		currentMiddleAsteroid.direction.y = 0;
		currentMiddleAsteroid.speed = MAX_MIDDLE_ASTEROID_SPEED;
		currentMiddleAsteroid.countTime = 0.0f;
		currentMiddleAsteroid.radius = 35;
		currentMiddleAsteroid.isDestroyed = true;
		currentMiddleAsteroid.maxTime = randomSpawnTime;
	}

	void SmallAsteroidInit(Asteroids& currentSmallAsteroid)
	{
		float randomSpawnTime = static_cast<float>(rand() % (5 - 2 + 1) + 1);

		currentSmallAsteroid.position.x = 0;
		currentSmallAsteroid.position.y = 0;
		currentSmallAsteroid.direction.x = 0;
		currentSmallAsteroid.direction.y = 0;
		currentSmallAsteroid.speed = MAX_SMALL_ASTEROID_SPEED;
		currentSmallAsteroid.countTime = 0.0f;
		currentSmallAsteroid.radius = 20;
		currentSmallAsteroid.isDestroyed = true;
		currentSmallAsteroid.maxTime = randomSpawnTime;
	}

	void SetAsteroidDirection(Asteroids& currentAsteroid)
	{
		do
		{
			currentAsteroid.direction.x = static_cast<float>(rand() % 3 - 1);
			currentAsteroid.direction.y = static_cast<float>(rand() % 3 - 1);

		} while (currentAsteroid.direction.x == 0 && currentAsteroid.direction.y == 0);
	}

	void SpawnTimeAsteroids(Asteroids& currentBigAsteroid, float delta)
	{
		currentBigAsteroid.countTime += delta;

		if (currentBigAsteroid.countTime <= currentBigAsteroid.maxTime)
		{
			SpawnBigAsteroid();
			currentBigAsteroid.countTime = 0.0f;
			currentBigAsteroid.maxTime = static_cast<float>(rand() % (5 - 2 + 1) + 2);
		}
	}


	void SpawnBigAsteroid()
	{
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			if (bigAsteroid[i].isDestroyed == true)
			{
				BigAsteroidInit(bigAsteroid[i]);
				SetAsteroidDirection(bigAsteroid[i]);

				bigAsteroid[i].isDestroyed = false;

				break;
			}
		}
	}

	void SpawnMiddleAsteroid(Vector2 position)
	{
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			if (middleAsteroid[i].isDestroyed == true)
			{
				MiddleAsteroidInit(middleAsteroid[i]);
				middleAsteroid[i].position = position;
				SetAsteroidDirection(middleAsteroid[i]);

				middleAsteroid[i].isDestroyed = false;

				break;
			}
		}
	}

	void SpawnSmallAsteroid(Vector2 position)
	{
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			if (smallAsteroid[i].isDestroyed == true)
			{
				SmallAsteroidInit(smallAsteroid[i]);
				smallAsteroid[i].position = position;
				SetAsteroidDirection(smallAsteroid[i]);

				smallAsteroid[i].isDestroyed = false;

				break;
			}
		}
	}

	void AsteroidsUpdate(float delta)
	{
		bool inCollision = false;

		SpawnTimeAsteroids(bigAsteroid[0], delta);

		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			if (bigAsteroid[i].isDestroyed == false)
			{
				bigAsteroid[i].position.x += bigAsteroid[i].direction.x * bigAsteroid[i].speed * delta;
				bigAsteroid[i].position.y += bigAsteroid[i].direction.y * bigAsteroid[i].speed * delta;

				GoToaSidetoAnother(bigAsteroid[i]);
			}

			if (middleAsteroid[i].isDestroyed == false)
			{
				middleAsteroid[i].position.x += middleAsteroid[i].direction.x * middleAsteroid[i].speed * delta;
				middleAsteroid[i].position.y += middleAsteroid[i].direction.y * middleAsteroid[i].speed * delta;

				GoToaSidetoAnother(middleAsteroid[i]);
			}

			if (smallAsteroid[i].isDestroyed == false)
			{
				smallAsteroid[i].position.x += smallAsteroid[i].direction.x * smallAsteroid[i].speed * delta;
				smallAsteroid[i].position.y += smallAsteroid[i].direction.y * smallAsteroid[i].speed * delta;

				GoToaSidetoAnother(smallAsteroid[i]);
			}
		}

		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (bullets[i].isActive == false)
			{
				continue; //Avanza entre las balas para ver cual esta activa
			}
			//COLISION DEL ASTEROIDE GRANDE
			inCollision = false;

			for (int j = 0; j < MAX_ASTEROIDS; j++)
			{
				if (bigAsteroid[j].isDestroyed == false)
				{
					inCollision = CollisionCircleCircle(bigAsteroid[j].position, bigAsteroid[j].radius, bullets[i].position, bullets[i].radius);

					if (inCollision)
					{
						bigAsteroid[j].isDestroyed = true;
						bullets[i].isActive = false;
						player.score++;

						int quantity = 0;

						Vector2 spawnPosition = bigAsteroid[j].position;

						spawnPosition.x += bigAsteroid[j].radius + 10;

						while (quantity < 2)
						{
							SpawnMiddleAsteroid(spawnPosition);

							quantity++;

							spawnPosition = bigAsteroid[j].position;
							spawnPosition.x -= bigAsteroid[j].radius - 10;
						}

						break;
					}
				}
			}

			if (inCollision)
			{
				continue; // Si colisiona, pasa a la siguiente iteracion
			}

			for (int k = 0; k < MAX_ASTEROIDS; k++)
			{
				if (middleAsteroid[k].isDestroyed == false)
				{
					inCollision = CollisionCircleCircle(middleAsteroid[k].position, middleAsteroid[k].radius, bullets[i].position, bullets[i].radius);

					if (inCollision)
					{
						middleAsteroid[k].isDestroyed = true;
						bullets[i].isActive = false;
						player.score++;

						int quantity = 0;

						Vector2 spawnPosition = middleAsteroid[k].position;

						spawnPosition.x += middleAsteroid[k].radius + 10;

						while (quantity < 2)
						{
							SpawnSmallAsteroid(spawnPosition);

							quantity++;

							spawnPosition = middleAsteroid[k].position;
							spawnPosition.x -= middleAsteroid[k].radius - 10;
						}

						break;
					}
				}
			}

			if (inCollision)
			{
				continue;
			}

			//COLISION DEL ASTEROIDE MAS CHIQUITO

			for (int k = 0; k < MAX_ASTEROIDS; k++)
			{
				if (smallAsteroid[k].isDestroyed == false)
				{
					inCollision = CollisionCircleCircle(smallAsteroid[k].position, smallAsteroid[k].radius, bullets[i].position, bullets[i].radius);

					if (inCollision)
					{
						smallAsteroid[k].isDestroyed = true;
						bullets[i].isActive = false;
						player.score++;
						break;
					}
				}
			}
		}
	}


void BigAsteroidDraw()
{
	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		if (bigAsteroid[i].isDestroyed == false)
		{
#ifdef _DEBUG
			DrawCircleV(bigAsteroid[i].position, bigAsteroid[i].radius, RED);
#endif
		}
	}
}

void MiddleAsteroidDraw()
{
	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		if (middleAsteroid[i].isDestroyed == false)
		{
#ifdef _DEBUG
			DrawCircleV(middleAsteroid[i].position, middleAsteroid[i].radius, RED);
#endif
		}
	}
}

void SmallAsteroidDraw()
{
	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		if (smallAsteroid[i].isDestroyed == false)
		{
#ifdef _DEBUG
			DrawCircleV(smallAsteroid[i].position, smallAsteroid[i].radius, RED);
#endif
		}
	}
}

void GoToaSidetoAnother(Asteroids& asteroid)
{
	if (asteroid.position.x > WINDOW_WIDTH)
	{
		asteroid.position.x = 0;
	}
	else if (asteroid.position.x < 0)
	{
		asteroid.position.x = WINDOW_WIDTH;
	}

	if (asteroid.position.y > WINDOW_HEIGHT)
	{
		asteroid.position.y = 0;
	}
	else if (asteroid.position.y < 0)
	{
		asteroid.position.y = WINDOW_HEIGHT;
	}
}
}
