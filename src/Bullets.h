#pragma once
#include "raylib.h"

struct Bullets
{
	Vector2 position;
	Vector2 direction;
	float radius;
	float speed;
	float countTime;
	float maxTime;
	bool isActive;
};

const int MAX_BULLETS = 30;
const int MAX_BULLET_RADIUS = 15;

const float MAX_BULLET_SPEED = 300;
const float MAX_TIME = 3;

extern Bullets bullets[MAX_BULLETS];

void SetDirection(Bullets& bullet, Vector2 position);
void SetPosition(Bullets& bullet, Vector2 position);

void BulletsInit(Bullets& currentBullet);
void BulletsUpdate(Bullets& currentBullet, float delta);
void BulletsDraw(Texture2D confetti);

void ShotBullet(float delta);