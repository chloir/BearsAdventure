#include "DxLib.h"
#include "game_main.h"
#include "../support/Support.h"

extern int gamestate;

void titlescene() {
	DrawStringEx(500, 400, 0x00ffffff, "Press Space");

	if (IsKeyDownTrigger(KEY_INPUT_SPACE)) {
		gamestate = 1;
	}
}