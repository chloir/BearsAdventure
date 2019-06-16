#include "DxLib.h"
#include "../support/Support.h"
#include <random>
#include <time.h>

extern bool inbattle;

extern int points;

extern int bears;
extern int enemytimer;

extern int enemy_x;

bool enemyalive = false;

int enemyindex = 0;
std::mt19937 mt01(time(0));

int enemydelay = 120;

void enemypopper() {
	if (enemyalive == false) {
		enemytimer++;
	}

	// “GPOP‚ÉŠÔ‚ðŠJ‚¯‚é
	// “G’Š‘I
	if (enemyalive == false && enemytimer > enemydelay && inbattle == false) {
		enemyindex = mt01() % 3;
		enemytimer = 0;
		enemyalive = true;
		enemy_x = 1100;
	}

	if (enemyalive == true && inbattle == false) {
		switch (enemyindex) {
		case 0:
			if (IsKeyDownTrigger(KEY_INPUT_Q)) {
				inbattle = true;
			}
			break;

		case 1:
			if (IsKeyDownTrigger(KEY_INPUT_E)) {
				inbattle = true;
			}
			break;

		case 2:
			if (IsKeyDownTrigger(KEY_INPUT_W)) {
				inbattle = true;
			}
			break;
		}
	}
}

int GetEnemyIndex() { return enemyindex; }
bool GetEnemyAlive() { return enemyalive; }
void SetEnemyAlive(bool status) { enemyalive = status; }