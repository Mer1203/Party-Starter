#pragma once
#include "raylib.h"

struct Player
{
	Vector2 position;
	Vector2 direction;
	Vector2 speed;
	float radius;
	bool isAlive;
};

extern Player player;

const int MAX_SPEED = 500;

void PlayerInit();
void PlayerUpdate(float delta);
void PlayerDraw();
