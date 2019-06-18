#include "DxLib.h"
#include "game_main.h"
#include "../support/Support.h"
#include <time.h>
#include <math.h>
#include <random>

#define DEBUG 0

#if DEBUG
extern int enemytimer;
extern bool enemyalive;
extern int battlestat;
extern int bears;
extern int erapsedTime;
extern int Rframes;
extern int Bright;

extern int playerLife;

bool debugActive = false;

void ChangeGameState(int state);

void debugger() {
	DrawStringEx(10, 700, 0x00000000, "enemytimer:%d", enemytimer);
	DrawStringEx(10, 640, 0x00000000, "enemyalive:%d", enemyalive);
	DrawStringEx(10, 580, 0x00000000, "battlestat:%d", battlestat);
	DrawStringEx(10, 520, 0x00000000, "bears:%d", bears);
	DrawStringEx(10, 460, 0x00000000, "erapsedTime:%d", erapsedTime);
	DrawStringEx(10, 400, 0x00000000, "Rframes:%d", Rframes);
	DrawStringEx(10, 340, 0x00000000, "Bright:%d", Bright);
	if (IsKeyDownTrigger(KEY_INPUT_SPACE) && IsKeyDownTrigger(KEY_INPUT_LSHIFT)) {
		debugActive = true;
	}
}

void debugMode() {
	DrawStringEx(10, 10, 0x00000000, "DebugMode Active");
	if (IsKeyDownTrigger(KEY_INPUT_1)) {
		playerLife++;
	}
	if (IsKeyDownTrigger(KEY_INPUT_2)) {
		playerLife--;
	}
	if (IsKeyDownTrigger(KEY_INPUT_3)) {
		bears++;
	}
	if (IsKeyDownTrigger(KEY_INPUT_4)) {
		bears--;
	}
	if (IsKeyDownTrigger(KEY_INPUT_5)) {
		ChangeGameState(2);
	}
	if (IsKeyDownTrigger(KEY_INPUT_6)) {
		erapsedTime = 61;
	}
	if (IsKeyDownTrigger(KEY_INPUT_SPACE) && IsKeyDownTrigger(KEY_INPUT_D)) {
		debugActive = false;
	}
}

void CallDebugSystem() {
	debugger();
	if (debugActive) {
		debugMode();
	}
}
#endif