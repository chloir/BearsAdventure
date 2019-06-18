#include "DxLib.h"
#include "../support/Support.h"

int FaderFrames = 0;
int Bright = 255;
bool Finit = false;

void ChangeGameState(int state);

void FadeOut(int state) {
	if (!Finit) {
		Bright = 255;
		Finit = true;
	}
	if (Bright > 0) {
		Bright -= 6;
	}
	if (Bright < 10){
		Finit = false;
		ChangeGameState(state);
	}

	SetDrawBright(Bright, Bright, Bright);
}

void FadeIn(bool fade) {
	if (!Finit) {
		Bright = 0;
		Finit = true;
	}
	if (Bright < 255) {
		Bright++;
	}
	if (Bright > 255) {
		Bright = 255;
		fade = false;
	}

	SetDrawBright(Bright, Bright, Bright);
}

int GetBright() { return Bright; }
void AddBright() { Bright++; }
void MinusBright() { Bright--; }