#include "DxLib.h"
#include "game_main.h"
#include "../support/Support.h"
#include <time.h>
#include <math.h>
#include <random>

bool gameplayed = false;

// 0:�^�C�g��, 1:�Q�[�����, 2:���U���g���
int gamestate = 0;

int points = 0;

int enemytimer = 0;

//�v���g�^�C�v�錾
void gameplay();
void titlescene();
void ResultScreen();
void debugger();

//=============================================================================
// name... game_main
// work... �Q�[���̃��C�����[�v
// arg.... none
// ret.... [ ����I�� : 0 ]
//=============================================================================
int game_main()
{
	SetFontSize(40);

	switch (gamestate) {
		case 0:
			titlescene();
			break;

		case 1:
			gameplay();
			break;

		case 2:
			ResultScreen();
			break;
	}

	debugger();

	return 0 ;
}

void ChangeGameState(int state) { gamestate = state; }

