#pragma once
#include "raylib.h"
#include "GameManager.h"

const int positionButtonX = 300;

const int positionButtonPlayY = 180;
const int positionButtonRulesY = 280;
const int positionButtonCreditsY = 380;
const int positionButtonExitY = 480;

const int widthButton = 220;
const int heightButton = 80;

const int positionGameNameX = 170;
const int positionGameNameY = 90;
const int fontSizeGameName = 80;

const int positionTextX = 300;
const int positionTextY = 80;

const int fontSizeButtonName = 40;

const int positionButtonNamePlayX = 344;
const int positionButtonNamePlayY = 200;

const int positionButtonNameRulesX = 330;
const int positionButtonNameRulesY = 300;

const int positionButtonNameCreditsX = 304;
const int positionButtonNameCreditsY = 400;

const int positionButtonNameExitX = 345;
const int positionButtonNameExitY = 500;

const int positionBackButtonX = 0;
const int positionBackButtonY = 0;
const int backButtonWidth = 90;
const int backButtonHeight = 30;

bool CheckCollisionMouseButton(Vector2 mousePosition, int buttonX, int buttonY, int buttonHeight, int buttonWidth);
void IsMousePressed();
void IsMousePressingBackButton();
void ButtonDrawing(Vector2 MousePosition);
void ButtonText(Vector2 MousePosition);
void BackMenuButton();

