#include "Queen.h"
#include "Color2.h"

#include <stdlib.h>

bool Queen::checkMove(Type typeEnd, Color colorEnd, int rowStart, int colStart, int rowEnd, int colEnd) const {
	int rowAdj, colAdj;
	if (rowStart == rowEnd) { //right-left movement
		colAdj = (colEnd - colStart) / abs(colEnd - colStart);
		for (int i = colStart + colAdj; i != colEnd; i += colAdj) {
			/*
			if (m_board[rowStart][i] != "nullptr")
				return false;
			*/
		}
	}
	else if (colStart == colEnd) { //up-down movement
		rowAdj = (rowEnd - rowStart) / abs(rowEnd - rowStart);
		for (int i = rowStart + rowAdj; i != rowStart; i += rowAdj) {
			/*
			if (m_board[i][colStart] != "nullptr")
				return false;
			*/
		}
	}
	else if (abs(rowStart - rowEnd) == abs(colStart - colEnd)) { //diagnal movement
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
	if (typeEnd->getColor != m_color) //if piece lands on different color piece.
		return true;
	else
		return false;
	*/
}