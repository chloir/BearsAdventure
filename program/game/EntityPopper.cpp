#include "DxLib.h"
#include "game_main.h"
#include "../support/Support.h"
#include <time.h>
#include <math.h>
#include <random>

bool popperinit = false;

std::mt19937 entity_mt(time(0));

int baloonImage = 0;

int baloonX = 900;
int baloonY = 900;

int baloonTimer = 0;
bool baloonAlive = false;

void BaloonPopper() {
	if (popperinit == false) {
		baloonImage = LoadGraph("graphics/BaloonA");
	}

	if (baloonAlive == false) {
		// int randomPopper = entity_mt() % 10;
		baloonAlive = true;
	}

	if (baloonAlive == true) {
		DrawGraph(baloonX, baloonY, baloonImage, true);
		baloonY -= 4;
		if (IsKeyDownTrigger(KEY_INPUT_B)) {
			baloonAlive = false;
		}
	}

	if (baloonY < -10) {
		baloonAlive = false;
		baloonY = 900;
	}
}