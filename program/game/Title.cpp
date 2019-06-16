#include "DxLib.h"
#include "game_main.h"
#include "../support/Support.h"

void ChangeGameState(int state);

void titlescene() {
	DrawStringEx(500, 400, 0x00ffffff, "Press Space");

	if (IsKeyDownTrigger(KEY_INPUT_SPACE)) {
		ChangeGameState(1);
	}
}