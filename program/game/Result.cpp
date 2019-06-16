#include "DxLib.h"
#include "../support/Support.h"
#include <random>
#include <time.h>

extern int points;
extern int gamestate;

// ƒŠƒUƒ‹ƒg‰æ–Ê
void ResultScreen() {

	DrawStringEx(300, 400, 0x00ffffff, "Result");
	DrawStringEx(300, 500, 0x00ffffff, "¡‰ñ‚ÌŒ‹‰Ê:%d", points);
	DrawStringEx(200, 680, 0x00ffffff, "Press Space To Return Title");

	if (IsKeyDownTrigger(KEY_INPUT_SPACE)) {
		points = 0;
		gamestate = 0;
	}
}