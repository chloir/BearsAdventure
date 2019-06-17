#include "DxLib.h"
#include "../support/Support.h"

int enemy_x = 1100;
int enemy_y = 350;

bool EdrawInit = false;

extern int enemy01;
extern int enemy02;
extern int enemy03;

void DrawEnemy(int enemyindex, bool enemyalive) {
	if (EdrawInit) {
		enemy_x = 1100;
		enemy_y = 350;
		EdrawInit = true;
	}

	if (enemyalive == true) {
		if (enemy_x > 700) {
			enemy_x -= 20;
		}

		switch (enemyindex) {
		case 0:
			DrawExtendGraph(enemy_x, enemy_y, enemy_x + 200, enemy_y + 300, enemy01, true);
			break;

		case 1:
			DrawExtendGraph(enemy_x, enemy_y, enemy_x + 200, enemy_y + 300, enemy03, true);
			break;

		case 2:
			DrawExtendGraph(enemy_x, enemy_y, enemy_x + 200, enemy_y + 300, enemy02, true);
			break;
		}
	}
}