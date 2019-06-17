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
	SetFontSize(40);

	if (!timerInit) {
		startTime = time(0);
		timerInit = true;
	}

	if (!GetPlayerAlive()) {
		ChangeGameState(2);
	}
	
	int enindex = GetEnemyIndex();

	currentTime = time(0);
	erapsedTime = currentTime - startTime;

	if (erapsedTime > 60) {
		ChangeGameState(2);
	}

	DrawBG();
	DrawPlayer();

	bool alive = GetEnemyAlive();
	enemypopper();

	if (alive == true) {
		DrawEnemy(enindex, alive);
	}

	if (inbattle == true) {
		battlescene();
	}

	if (GetIsResult() == true) {
		BattleResultScene();
	}
}

void SetInBattle(bool status) { inbattle = status; }
int GetCurrentT() { return currentTime; }
int GetErapsedT() { return erapsedTime; }