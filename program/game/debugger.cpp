#include "DxLib.h"
#include "game_main.h"
#include "../support/Support.h"
#include <time.h>
#include <math.h>
#include <random>

extern int enemytimer;
extern bool enemyalive;
extern int battlestat;
extern int bears;
extern int erapsedTime;

void debugger() {
	DrawStringEx(10, 700, 0x00000000, "enemytimer:%d", enemytimer);
	DrawStringEx(10, 640, 0x00000000, "enemyalive:%d", enemyalive);
	DrawStringEx(10, 580, 0x00000000, "battlestat:%d", battlestat);
	DrawStringEx(10, 520, 0x00000000, "bears:%d", bears);
	DrawStringEx(10, 460, 0x00000000, "erapsedTime:%d", erapsedTime);
}