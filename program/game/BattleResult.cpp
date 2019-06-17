#include "DxLib.h"
#include "../support/Support.h"
#include <string>

extern int msgwindow;
bool isResult = false;
bool resultInit = false;

int resultLifeTime = 0;
int frames = 0;

std::string winmessage("Ÿ—˜I");
std::string losemessage("”s–kI");
std::string drawmessage("‚ ‚¢‚±");

void StringDrawer(std::string str, int counter);
void SetEnemyAlive(bool status);
void BattleInitialize();
int GetBattleStat();
void AddBears();
int GetEnemyIndex();
int GetBears();
void ChangePlayerLife(bool Add);
void SetResult(bool status) { isResult = status; }
bool GetIsResult() { return isResult; }


void BattleResultScene() {
	if (resultInit == false) {
		resultLifeTime = 160;
		frames = 0;
		resultInit = true;
	}

	frames++;
	DrawGraph(20, 600, msgwindow, true);

	switch (GetBattleStat()) {
	case 0:
		StringDrawer(winmessage, frames);
		break;

	case 1:
		StringDrawer(losemessage, frames);
		break;

	case 2:
		StringDrawer(drawmessage, frames);
		break;
	}

	if (frames > resultLifeTime) {
		if (GetEnemyIndex() == 1 && GetBattleStat() == 0) {
			if (GetBears() < 4) {
				AddBears();
			}
		}
		if (GetEnemyIndex() == 0 && GetBattleStat() == 1) {
			ChangePlayerLife(false);
		}
		if (GetEnemyIndex() == 2 && GetBattleStat() == 0) {
			ChangePlayerLife(true);
		}
		isResult = false;
		resultInit = false;
		SetEnemyAlive(false);
		BattleInitialize();
	}
}

void StringDrawer(std::string str, int counter) {
	int message_length = counter / 4;
	if (message_length > str.length()) {
		message_length = str.length();
	}
	std::string draw_str = str.substr(0, message_length);
	DrawStringEx(450, 640, 0x000000, "%s", draw_str.c_str());
}