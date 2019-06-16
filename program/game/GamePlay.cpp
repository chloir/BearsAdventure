#include "DxLib.h"
#include "../support/Support.h"
#include <time.h>
#include <math.h>
#include <random>

extern bool gameplayed;

extern int points;

extern int framecount;

extern int gamestate;

bool inbattle = false;
bool timerInit = false;

int startTime = 0;
int erapsedTime = 0;
int currentTime = 0;

void enemypopper();
void DrawPlayer();
void DrawBG();
void battlescene();
void DrawEnemy(int enemyindex, bool enemyalive);
int GetEnemyIndex();
bool GetEnemyAlive();
bool GetIsResult();
void BattleResultScene();
void ChangeGameState(int state);
bool GetPlayerAlive();

void gameplay() {
	if (!timerInit) {
		startTime = time(0);
		timerInit = true;
	}

	if (GetPlayerAlive()) {
		ChangeGameState(2);
	}
	
	int enindex = GetEnemyIndex();

	currentTime = time(0);
	erapsedTime = currentTime - startTime;

	DrawBG();
	DrawPlayer();

	bool alive = GetEnemyAlive();
	enemypopper();

	// ìGï`âÊÇ∆çUåÇ(?)îªíË
	if (alive == true) {
		DrawEnemy(enindex, alive);
	}

	if (inbattle == true) {
		battlescene();
	}

	if (GetIsResult() == true) {
		BattleResultScene();
	}

	if (IsKeyDownTrigger(KEY_INPUT_SPACE)) {
		ChangeGameState(2);
	}
}

void SetInBattle(bool status) { inbattle = status; }
int GetCurrentT() { return currentTime; }