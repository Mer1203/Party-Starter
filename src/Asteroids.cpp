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

	void BigAsteroidInit(Asteroids& currentBigAsteroid)
	{
		float randomSpawnTime = static_cast<float>(rand() % (5 - 2 + 1) + 2);

		currentBigAsteroid.position.x = 0;
		currentBigAsteroid.position.y = 0;
		currentBigAsteroid.direction.x = 0;
		currentBigAsteroid.direction.y = 0;
		currentBigAsteroid.speed = MAX_BIG_ASTEROID_SPEED;
		currentBigAsteroid.countTime = 0.0f;
		currentBigAsteroid.radius = 40;
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
		currentMiddleAsteroid.radius = 25;
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
		currentSmallAsteroid.radius = 10;
		currentSmallAsteroid.isDestroyed = true;
		currentSmallAsteroid.maxTime = randomSpawnTime;
	}

	void SetAsteroidDirection(Asteroids& currentAsteroid)
	{
		int randomDirection = 0;

		//Dandole una direccion random:
		randomDirection = rand() % (1 - (-1) + 1);
		currentAsteroid.direction.x = static_cast<float>(randomDirection);
		randomDirection = rand() % (1 - (-1) + 1);
		currentAsteroid.direction.y = static_cast<float>(randomDirection);
	}

	void SpawnTimeAsteroids(Asteroids& currentBigAsteroid, float delta)
	{
		currentBigAsteroid.countTime += delta;

		if (currentBigAsteroid.countTime <= currentBigAsteroid.maxTime)
		{
			SpawnBigAsteroid();
			SetAsteroidDirection(currentBigAsteroid);
		}
	}


	void SpawnBigAsteroid()
	{
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			if (bigAsteroid[i].isDestroyed == true)
			{
				BigAsteroidInit(bigAsteroid[i]);

				bigAsteroid[i].isDestroyed = false;

				break;
			}
		}
	}

	void SpawnMiddleAsteroid()
	{
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			if (middleAsteroid[i].isDestroyed == true)
			{
				MiddleAsteroidInit(middleAsteroid[i]);
				SetAsteroidDirection(middleAsteroid[i]);

				middleAsteroid[i].isDestroyed = false;

				break;
			}
		}
	}

	void SpawnSmallAsteroid()
	{
		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			if (smallAsteroid[i].isDestroyed == true)
			{
				SmallAsteroidInit(smallAsteroid[i]);
				SetAsteroidDirection(smallAsteroid[i]);

				smallAsteroid[i].isDestroyed = false;

				break;
			}
		}
	}

	void AsteroidsUpdate(float delta)
	{
		bool inCollision = false;

		for (int i = 0; i < MAX_ASTEROIDS; i++)
		{
			SpawnTimeAsteroids(bigAsteroid[i], delta);

			if (bigAsteroid[i].isDestroyed == false)
			{
				GoToaSidetoAnother(bigAsteroid[i]);
			}

			if (middleAsteroid[i].isDestroyed == false)
			{
				GoToaSidetoAnother(middleAsteroid[i]);
			}

			if (smallAsteroid[i].isDestroyed == false)
			{
				GoToaSidetoAnother(smallAsteroid[i]);
			}
		}

		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (bullets[i].isActive)
			{
				//COLISION DEL ASTEROIDE GRANDE
				inCollision = false;
				for (int j = 0; j < MAX_ASTEROIDS; j++)
				{
					if (bigAsteroid[j].isDestroyed == false)
					{
						bigAsteroid[j].position.x += bigAsteroid[j].direction.x * bigAsteroid[j].speed * delta;
						bigAsteroid[j].position.y += bigAsteroid[j].direction.y * bigAsteroid[j].speed * delta;




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
								SpawnMiddleAsteroid();

								quantity++;

								spawnPosition = bigAsteroid[j].position;
								spawnPosition.x -= bigAsteroid[j].radius - 10;
							}

							break;
						}

					}

					//COLISION DEL ASTEROIDE MEDIANO
					inCollision = false;

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
									SpawnSmallAsteroid();

									quantity++;

									spawnPosition = middleAsteroid[k].position;
									spawnPosition.x -= middleAsteroid[k].radius - 10;

								}
								break;
							}
						}
					}

					//COLISION DEL ASTEROIDE MAS CHIQUITO
					inCollision = false;
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
							}
						}
					}

					if (inCollision)
					{
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
