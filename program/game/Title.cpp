#include "DxLib.h"
#include "game_main.h"
#include "../support/Support.h"

extern int titleSc01;
extern int titleSc02;

int Tframes;

void ChangeGameState(int state);

void titlescene() {
	SetFontSize(60);

	if (Tframes > 60) {
		Tframes = 0;
	}
	Tframes++;

	if (Tframes < 30) {
		DrawGraph(0, 0, titleSc01, false);
	}
	else {
		DrawGraph(0, 0, titleSc02, false);
	}

	DrawStringEx(250, 300, 0x00cdb133, "Bear's Adventure!");
	SetFontSize(30);
	DrawStringEx(400, 600, 0x00ffffff, "Press Space");

	if (IsKeyDownTrigger(KEY_INPUT_SPACE)) {
		ChangeGameState(1);
	}
}