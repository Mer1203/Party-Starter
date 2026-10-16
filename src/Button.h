#pragma once
#include "raylib.h"
#include "GameManager.h"



struct Button
{
	float x;
	float y;
	float textX;
	float textY;
	float textSize;
	float width;
	float height;
	bool isPressed;
};

Button play;
Button rules;
Button credits;
Button exit;
Button back;

void ButtonInit();
bool CheckCollisionMouseButton(Vector2 mousePosition, int buttonX, int buttonY, int buttonHeight, int buttonWidth);
void IsMousePressed();
void IsMousePressingBackButton();
void ButtonDrawing(Vector2 MousePosition);
void ButtonText(Vector2 MousePosition);
void BackMenuButton();

