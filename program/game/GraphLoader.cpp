#include "DxLib.h"
#include "../support/Support.h"

int msgwindow = 0;
int bearHandMask = 0;
int rockpng = 0;
int scisorspng = 0;
int paperpng = 0;
int playerSprite3 = 0;
int playerSprite2 = 0;
int playerSprite1 = 0;
int friendlyBear = 0;
int enemy01 = 0;
int enemy02 = 0;
int enemy03 = 0;

void GraphLoader() {
	msgwindow = LoadGraph("graphics/msgwindow.png");

	bearHandMask = LoadGraph("graphics/BearHandMask.png");
	rockpng = LoadGraph("graphics/BearRock.png");
	scisorspng = LoadGraph("graphics/BearScisors.png");
	paperpng = LoadGraph("graphics/BearPaper.png");

	playerSprite3 = LoadGraph("graphics/BaloonBear3.png");
	playerSprite2 = LoadGraph("graphics/BaloonBear2.png");
	playerSprite1 = LoadGraph("graphics/BaloonBear1.png");

	friendlyBear = LoadGraph("graphics/BearBack.png");

	enemy01 = LoadGraph("graphics/Bird.png");
	enemy02 = LoadGraph("graphics/BaloonC.png");
	enemy03 = LoadGraph("graphics/FriendlyBear.png");
}