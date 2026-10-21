#pragma once
#include "raylib.h"

struct Player
{
	Vector2 position;
	Vector2 direction;
	Vector2 speed;
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

const int MAX_PLAYER_SPEED = 400;

void PlayerInit(Texture2D canion);
void PlayerUpdate(float delta);
void PlayerDraw(Texture2D canion);
