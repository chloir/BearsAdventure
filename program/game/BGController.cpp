#include "DxLib.h"
#include "game_main.h"
#include "../support/Support.h"
#include <time.h>
#include <math.h>

bool bgloaded = false;

int bg = 0;
int bgNight = 0;
int bgDawn = 0;

int bg_x1 = 0;
int bg_y1 = 0;
int bg_x2 = 1024;
int bg_y2 = 768;

int bg_x3 = 0;
int bg_y3 = -768;
int bg_x4 = 1024;
int bg_y4 = 0;

int scrollrate = 4; // スクロール速度

int GetErapsedT();

void DrawBG() {
	if (bgloaded == false) {
		bg = LoadGraph("graphics/skybg.png");
		bgNight = LoadGraph("graphics/BGNight.png");
		bgDawn = LoadGraph("graphics/BGDawn.png");
		bgloaded = true;
	}

	int eT = GetErapsedT();

	if (eT < 20) {
		DrawExtendGraph(bg_x1, bg_y1, bg_x2, bg_y2, bg, false);
		DrawExtendGraph(bg_x3, bg_y3, bg_x4, bg_y4, bg, false);
	}
	else if (eT < 40) {
		DrawExtendGraph(bg_x1, bg_y1, bg_x2, bg_y2, bgDawn, false);
		DrawExtendGraph(bg_x3, bg_y3, bg_x4, bg_y4, bgDawn, false);
	}
	else {
		DrawExtendGraph(bg_x1, bg_y1, bg_x2, bg_y2, bgNight, false);
		DrawExtendGraph(bg_x3, bg_y3, bg_x4, bg_y4, bgNight, false);
	}

	//BGスクロール処理
	if (bg_y1 > 768) {
		bg_x1 = bg_x3;
		bg_y1 = -768;
		bg_x2 = bg_x4;
		bg_y2 = 5;
	}

	if (bg_y3 > 768) {
		bg_x3 = bg_x1;
		bg_y3 = -768;
		bg_x4 = bg_x2;
		bg_y4 = 5;
	}

	bg_y1 += scrollrate;
	bg_y2 += scrollrate;
	bg_y3 += scrollrate;
	bg_y4 += scrollrate;
}

void DrawSimpleBG(int index) {
	if (index == 0) {
		DrawExtendGraph(bg_x1, bg_y1, bg_x2, bg_y2, bg, false);
		DrawExtendGraph(bg_x3, bg_y3, bg_x4, bg_y4, bg, false);
	}
	else if (index == 1) {
		DrawExtendGraph(bg_x1, bg_y1, bg_x2, bg_y2, bgNight, false);
		DrawExtendGraph(bg_x3, bg_y3, bg_x4, bg_y4, bgNight, false);
	}

	if (bg_y1 > 768) {
		bg_x1 = bg_x3;
		bg_y1 = -768;
		bg_x2 = bg_x4;
		bg_y2 = 5;
	}

	if (bg_y3 > 768) {
		bg_x3 = bg_x1;
		bg_y3 = -768;
		bg_x4 = bg_x2;
		bg_y4 = 5;
	}

	bg_y1 += scrollrate;
	bg_y2 += scrollrate;
	bg_y3 += scrollrate;
	bg_y4 += scrollrate;
}