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
bool playerAlive = false;

int startTime = 0;
int erapsedTime = 0;

void enemypopper();
void DrawPlayer();
void DrawBG();
void battlescene();
void DrawEnemy(int enemyindex, bool enemyalive);
int GetEnemyIndex();
bool GetEnemyAlive();
bool GetIsResult();
void BattleResultScene();

void gameplay() {
	if (!timerInit) {
		startTime = time(0);
		timerInit = true;
	}
	
	int enindex = GetEnemyIndex();

	int currentTime = time(0);
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
		gamestate = 2;
	}
}

void SetInBattle(bool status) { inbattle = status; }
void SetPlayerAlive(bool status) { playerAlive = status; }
int GetErapsedTime() { return erapsedTime; }