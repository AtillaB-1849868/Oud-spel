#include "Knight.h"
#include "Color2.h"

#include <stdlib.h>

bool Knight::checkKnightMove(int typeEnd, int rowStart, int colStart, int rowEnd, int colEnd) {
	if ((abs(rowStart - rowEnd) != 2 && abs(colStart - colEnd) != 1) && (abs(rowStart - rowEnd) != 1 && abs(rowEnd - colEnd) != 2))
	{
		return false;
	}
	/*
	if (typeEnd->getColor != m_color) //if langs on different color piece.		//LETS PUT THIS BIJ CHESSBOARD ZELF NOG.. Nog een check voor checkmoves... gaat bij elke piece gebeure
		return true;
	else
		return false;
	*/
}