#include "Knight.h"
#include "Color2.h"
#include "Chessboard2.h"
#include <stdlib.h>

bool Knight::checkMove(Type typeEnd, Color colorEnd, int rowStart, int colStart, int rowEnd, int colEnd, const Piece* board[8][8]) const {
	if ((abs(rowStart - rowEnd) != 2 && abs(colStart - colEnd) != 1) && (abs(rowStart - rowEnd) != 1 && abs(rowEnd - colEnd) != 2)) //if it doesn't match this movement
	{
		return false;
	}
	else
		return true;

	if (colorEnd != getColor())  //if piece lands on different color piece.
		return true;
	else
		return false;
}