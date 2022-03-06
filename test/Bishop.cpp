#include "Bishop.h"
#include "Color2.h"

#include <stdlib.h>

bool Bishop::checkMove(Type typeEnd, Color colorEnd, int rowStart, int colStart, int rowEnd, int colEnd) const {
	int rowAdj, colAdj;

	if (abs(rowStart - rowEnd) == abs(colStart - colEnd)) { //diagnal movement
		rowAdj = (rowEnd - rowStart) / abs(rowEnd - rowStart); //up-down
		colAdj = (colEnd - colStart) / abs(colEnd - colStart); //left-right
		int j = colStart + colEnd;
		for (int i = rowStart + rowAdj; i < abs(rowStart - rowEnd); i += rowAdj) { //Moet nog getest worden, check for pieces in its path
			/*
			if (m_board[i][j] != "nullptr")
			*/
			j += colAdj;
		}

	}
	else
		return false;
	/*
	if (typeEnd->getColor != m_color)  //if piece lands on different color piece.
		return true;
	else
		return false;
	*/
}