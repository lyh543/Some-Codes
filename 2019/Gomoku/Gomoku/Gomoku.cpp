#include "GomokuUI.h"
#include "GomokuAI.h"

#define _CRT_SECURE_NO_WARNINGS

#define DEBUG
#define DEBUG_CALCULATE_SCORE
//#define DEBUG_PIECE_IN_LINE

int main()
{
	initializeProgram();
	runGame();
	return 0;
}
