#include "DxLib.h"
#include "../support/Support.h"
#include <random>
#include <time.h>

enum hand {
	rock,
	scisors,
	paper
};

enum selectedHand {
	rockSelected,
	scisorsSelected,
	paperSelected
};

bool isWon = false;
bool selected = false;
bool battleinit = false;

int battlestat = 0; // 0:èüÇø, 1:ïâÇØ, 2:Ç†Ç¢Ç±
int selectedHandIndex = 0;

extern int msgwindow;
extern int bearHandMask;
extern int rockpng;
extern int scisorspng;
extern int paperpng;

int handPicX = 100;
int handPicY = 300;

int selectedX = 400;

hand enemy;
hand player;

std::mt19937 mt(time(0));
int enemyhand = 0;

void battle();
void DrawEnemy(int enemyindex, bool enemyalive);
void DrawPlayer();
int GetEnemyIndex();
bool GetEnemyAlive();
void SetResult(bool status);
void SetInBattle(bool status);

void BattleInitialize() {
	battlestat = 0;
	enemyhand = 0;
	selected = false;
}

// ÉoÉgÉãÇÃï`âÊ
void battlescene() {
	int index = GetEnemyIndex();
	bool alive = GetEnemyAlive();

	DrawPlayer();

	DrawEnemy(index, alive);

	if (selected == false) {
		int tempX = handPicX;
		DrawGraph(tempX, handPicY, rockpng, true);
		DrawGraph(tempX + 300, handPicY, scisorspng, true);
		DrawGraph(tempX + 600, handPicY, paperpng, true);

		switch (selectedHandIndex) {
		case 0:
			DrawGraph(tempX, handPicY, bearHandMask, true);
			break;
		case 1:
			DrawGraph(tempX + 300, handPicY, bearHandMask, true);
			break;
		case 2:
			DrawGraph(tempX + 600, handPicY, bearHandMask, true);
			break;
		}

		battle();
	}
	else {
		switch (player) {
		case rock:
			DrawGraph(selectedX, handPicY, rockpng, true);
			SetResult(true);
			SetInBattle(false);
			break;

		case scisors:
			DrawGraph(selectedX, handPicY, scisorspng, true);
			SetResult(true);
			SetInBattle(false);
			break;

		case paper:
			DrawGraph(selectedX, handPicY, paperpng, true);
			SetResult(true);
			SetInBattle(false);
			break;
		}
	}

	DrawGraph(20, 600, msgwindow, true);
}

void battle() {
	enemyhand = mt() % 3;

	switch (enemyhand) {
		case 0:
			enemy = rock;
			break;

		case 1:
			enemy = scisors;
			break;

		case 2:
			enemy = paper;
			break;
	}

	if (!selected) {
		if (IsKeyDownTrigger(KEY_INPUT_LEFT)) {
			selectedHandIndex--;
			if (selectedHandIndex < 0) {
				selectedHandIndex = 2;
			}
		}
		if (IsKeyDownTrigger(KEY_INPUT_RIGHT)) {
			selectedHandIndex++;
			if (selectedHandIndex > 2) {
				selectedHandIndex = 0;
			}
		}
		if (IsKeyDownTrigger(KEY_INPUT_RETURN)) {
			player = (hand)selectedHandIndex;
			selected = true;
		}
	}

	//if (IsKeyDownTrigger(KEY_INPUT_R)) {
	//	player = rock;
	//	selected = true;
	//}
	//else if (IsKeyDownTrigger(KEY_INPUT_S)) {
	//	player = scisors;
	//	selected = true;
	//}
	//else if (IsKeyDownTrigger(KEY_INPUT_P)) {
	//	player = paper;
	//	selected = true;
	//}

	if (selected) {
		switch (player) {
		case rock:
			if (enemy == rock) {
				battlestat = 2;
			}
			else if (enemy == paper) {
				battlestat = 1;
			}
			else {
				battlestat = 0;
			}

		case scisors:
			if (enemy == scisors) {
				battlestat = 2;
			}
			else if (enemy == rock) {
				battlestat = 1;
			}
			else {
				battlestat = 0;
			}

		case paper:
			if (enemy == paper) {
				battlestat = 2;
			}
			else if (enemy == scisors) {
				battlestat = 1;
			}
			else {
				battlestat = 0;
			}
		}
	}
}

int GetBattleStat() { return battlestat; }