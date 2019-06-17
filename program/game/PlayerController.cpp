#include "DxLib.h"
#include "game_main.h"
#include "../support/Support.h"
#include <time.h>
#include <math.h>

extern int playerSprite3;
extern int playerSprite2;
extern int playerSprite1;
extern int addBear;
int playerLife = 3;
bool playerAlive = true;

bool PcontInit = false;

int player_x = 80;
int player_y = 80;

int y_difference = 120;

int bears = 0;

void DrawPlayer() {
	if (!PcontInit) {
		playerLife = 3;
		bears = 0;
		playerAlive = true;
		PcontInit = true;
	}

	if (playerLife > 3) {
		playerLife = 3;
	}

	if (bears > 3) {
		bears = 4;
	}

	switch(playerLife){
	case 3:
		DrawGraph(player_x, player_y, playerSprite3, true);
		break;
	case 2:
		DrawGraph(player_x, player_y, playerSprite2, true);
		break;
	case 1:
		DrawGraph(player_x, player_y, playerSprite1, true);
		break;
	case 0:
		playerAlive = false;
		break;
	}

	// プレイヤーに仲間を連結
	if (bears != 0) {
		for (int i = 0; i < bears; i++) {
			DrawExtendGraph(player_x, player_y + y_difference, player_x + 100, player_y + 200 + y_difference, addBear, true);
			y_difference += 110;
		}
		y_difference = 200;
	}
}

void AddBears() { bears++; }
int GetBears() { return bears; }
void ChangePlayerLife(bool Add){
	if(Add){
		playerLife++;
	}else{
		playerLife--;
	}
}
void SetPlayerAlive(bool status) { playerAlive = status; }
bool GetPlayerAlive() { return playerAlive; }