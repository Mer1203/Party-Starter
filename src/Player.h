#pragma once
#include "raylib.h"

struct Player
{
	Vector2 position;
	Vector2 direction;
	float radius;
	bool isAlive;
};

extern Player player;

void PlayerInit();
void PlayerUpdate(float delta);
void PlayerDraw();
