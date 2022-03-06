#include "Queen.h"
#include "Color2.h"
#include "Chessboard2.h"
#include <stdlib.h>

bool Queen::checkMove(Type typeEnd, Color colorEnd, int rowStart, int colStart, int rowEnd, int colEnd, const Piece* board[8][8]) const {
	int rowAdj, colAdj;

	if (rowStart == rowEnd) { //right-left movement
		colAdj = (colEnd - colStart) / abs(colEnd - colStart);
		for (int i = colStart + colAdj; i != colEnd; i += colAdj) {
			if (board[rowStart][i] != nullptr)
				return false;
		}
	}
	else if (colStart == colEnd) { //up-down movement
		rowAdj = (rowEnd - rowStart) / abs(rowEnd - rowStart);
		for (int i = rowStart + rowAdj; i != rowEnd; i += rowAdj) {
			if (board[i][colStart] != nullptr)
				return false;
		}
	}
	else if (abs(rowStart - rowEnd) == abs(colStart - colEnd)) { //diagnal movement
		rowAdj = (rowEnd - rowStart) / abs(rowEnd - rowStart); //up-down
		colAdj = (colEnd - colStart) / abs(colEnd - colStart); //left-right
		for (int i = 1; i < abs(rowStart - rowEnd); i++) { //Moet nog getest worden, check for pieces in its path
			int x = rowStart + rowAdj * i;
			int y = colStart + colAdj * i;
			if (board[x][y] != nullptr)
				return false;
		}

	}
	else
		return false;

	if (colorEnd != getColor())  //if piece lands on different color piece.
		return true;
	else
		return false;
}