#pragma once
#include "Asteroids.h"
#include "raylib.h"

namespace Asteroids
{
	struct Player
	{
		Vector2 position;
		Vector2 direction;
		Vector2 speed;
		int score = 0;
		int lives;
		int height;
		int width;
		float rotation;
		float radius;
		bool isAlive;
	};

	extern Player player;
	extern Rectangle rectangle;

	extern Rectangle canionSource;
	extern Rectangle canionDestination;

	const int MAX_PLAYER_SPEED = 300;

	void PlayerGameOver(Asteroids& asteroid);
	void PlayerInit(Texture2D canion);
	void PlayerUpdate(float delta);
	void PlayerDraw(Texture2D canion);
}