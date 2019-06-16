#include "DxLib.h"
#include "game_main.h"
#include "../support/Support.h"
#include <time.h>
#include <math.h>
#include <random>

bool gameplayed = false;

// 0:タイトル, 1:ゲーム画面, 2:リザルト画面
int gamestate = 0;

int points = 0;

int enemytimer = 0;

//プロトタイプ宣言
void gameplay();
void titlescene();
void ResultScreen();
void debugger();

//=============================================================================
// name... game_main
// work... ゲームのメインループ
// arg.... none
// ret.... [ 正常終了 : 0 ]
//=============================================================================
int game_main()
{
	SetFontSize(40);

	switch (gamestate) {
		case 0:
			titlescene();
			break;

		case 1:
			gameplay();
			break;

		case 2:
			ResultScreen();
			break;
	}

	debugger();

	return 0 ;
}

void ChangeGameState(int state) { gamestate = state; }

