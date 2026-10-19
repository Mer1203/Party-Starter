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

const int MAX_SPEED = 400;

void PlayerInit();
void PlayerUpdate(float delta);
void PlayerDraw();
