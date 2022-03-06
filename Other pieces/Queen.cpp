#include "Queen.h"
#include "Color2.h"

#include <stdlib.h>

bool Queen::checkQueenMove(int typeEnd, int rowStart, int colStart, int rowEnd, int colEnd) {
	int rowAdj, colAdj;
	if (rowStart == rowEnd) { //right-left movement
		colAdj = (colEnd - colStart) / abs(colEnd - colStart);
		for (int i = colStart + colAdj; i != colEnd; i += colAdj) {
			/*
			if (m_board[rowStart][i] != "blank place")
				return false;
			*/
		}
	}
	else if (colStart == colEnd) { //up-down movement
		rowAdj = (rowEnd - rowStart) / abs(rowEnd - rowStart);
		for (int i = rowStart + rowAdj; i != rowStart; i += rowAdj) {
			/*
			if (m_board[i][colStart] != "blank place")
				return false;
			*/
		}
	}
	else if (abs(rowStart - rowEnd) == abs(colStart - colEnd)) { //diagnal movement
		rowAdj = (rowEnd - rowStart) / abs(rowEnd - rowStart); //up-down
		colAdj = (colEnd - colStart) / abs(colEnd - colStart); //left-right
		int j = colStart + colEnd;
		for (int i = rowStart + rowAdj; i < abs(rowStart - rowEnd); i += rowAdj) { //NIET ZEKER ABOUT THIS........
			/*
			if (m_board[i][j] != "blank place")
			*/
			j += colAdj;
		}
	
	}
	else
		return false;
	/*
	if (typeEnd->getColor != m_color) //if langs on different color piece.				//LETS PUT THIS BIJ CHESSBOARD ZELF NOG.. Nog een check voor checkmoves... gaat bij elke piece gebeure
		return true;
	else 
		return false;
	*/
}