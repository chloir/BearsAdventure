#include "DxLib.h"
#include "../support/Support.h"

int titleSc01 = 0;
int titleSc02 = 0;
int msgwindow = 0;
int bearHandMask = 0;
int rockpng = 0;
int scisorspng = 0;
int paperpng = 0;
int playerSprite3 = 0;
int playerSprite2 = 0;
int playerSprite1 = 0;
int addBear = 0;
int friendlyBear = 0;
int enemy01 = 0;
int enemy02 = 0;
int enemy03 = 0;
int result01 = 0;
int result01anim = 0;
int result02 = 0;
int result03 = 0;
int result04 = 0;

void GraphLoader() {
	titleSc01 = LoadGraph("graphics/Title01.png");
	titleSc02 = LoadGraph("graphics/Title02.png");

	msgwindow = LoadGraph("graphics/msgwindow.png");

	bearHandMask = LoadGraph("graphics/BearHandMask.png");
	rockpng = LoadGraph("graphics/BearRock.png");
	scisorspng = LoadGraph("graphics/BearScisors.png");
	paperpng = LoadGraph("graphics/BearPaper.png");

	playerSprite3 = LoadGraph("graphics/BaloonBear3.png");
	playerSprite2 = LoadGraph("graphics/BaloonBear2.png");
	playerSprite1 = LoadGraph("graphics/BaloonBear1.png");

	addBear = LoadGraph("graphics/AdditionalBear.png");
	friendlyBear = LoadGraph("graphics/BearBack.png");

	enemy01 = LoadGraph("graphics/Bird.png");
	enemy02 = LoadGraph("graphics/BaloonC.png");
	enemy03 = LoadGraph("graphics/FriendlyBear.png");

	result01 = LoadGraph("graphics/ResultWith1.png");
	result01anim = LoadGraph("graphics/ResultWith1anim.png");
	result02 = LoadGraph("graphics/ResultWith2.png");
	result03 = LoadGraph("graphics/ResultWith3.png");
	result04 = LoadGraph("graphics/ResultWith4.png");
}