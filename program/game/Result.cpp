#include "DxLib.h"
#include "../support/Support.h"
#include <random>
#include <time.h>

extern int gamestate;

extern int result01;
extern int result01anim;
extern int result02;
extern int result03;
extern int result04;

extern bool PcontInit;
extern bool timerInit;
extern bool EdrawInit;
extern bool EcontInit;
extern bool Tfade;
extern bool Tinit;

int Rframes = 0;

bool Rfade = false;
bool Rinit = false;

int GetBears();
bool GetPlayerAlive();
void ChangeGameState(int state);
void FadeOut(int state);

void GameInitializer() {
	PcontInit = false;
	timerInit = false;
	EdrawInit = false;
	EcontInit = false;
	Tfade = false;
	Tinit = false;
}

// リザルト画面
void ResultScreen() {
	if (!Rinit) {
		SetDrawBright(255, 255, 255);
		Rinit = true;
	}

	if (Rframes > 60)
	{
		Rframes = 0;
	}
	Rframes++;
	
	if (GetPlayerAlive()) {
		SetFontSize(60);
		switch (GetBears()) {
		case 0:
			if (Rframes < 30) {
				DrawGraph(0, 0, result01, false);
			}
			else {
				DrawGraph(0, 0, result01anim, false);
			}
			break;
		case 1:
			DrawGraph(0, 0, result02, false);
			break;
		case 2:
			DrawGraph(0, 0, result03, false);
			break;
		case 3:
			DrawGraph(0, 0, result04, false);
			break;
		}

		DrawStringEx(250, 60, 0x00ffda34, "Congraturations!");
		SetFontSize(40);
		if (GetBears() == 0) {
			DrawStringEx(300, 150, 0x00e1d730, "無事月に着いたクマ！");
		}
		else if(GetBears() < 3){
			DrawStringEx(300, 150, 0x00e1d730, "%d匹なかまにしたクマ！", GetBears());
		}
		else {
			DrawStringEx(300, 150, 0x00ffda34, "みんななかよしクマ！");
		}
	}
	else {
		SetFontSize(60);
		DrawStringEx(360, 350, 0x00bc394d, "Game Over");
	}

	SetFontSize(40);
	DrawStringEx(300, 600, 0x00ffda34, "Press Space To Title");

	if (IsKeyDownTrigger(KEY_INPUT_SPACE)) {
		GameInitializer();
		Rfade = true;
	}

	if (Rfade) {
		FadeOut(0);
	}
}