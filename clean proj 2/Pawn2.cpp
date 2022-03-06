#include "Pawn2.h"
#include "Color2.h"
#include <string>

bool Pawn2::checkPawnMove(int typeEnd, int rowStart, int colStart, int rowEnd, int colEnd) {
	int colDiff = colStart - colEnd;
	int rowDiff = rowStart - rowEnd;
	if (m_pawnColor == Color::white) {
		if (typeEnd != -1) {
			if (typeEnd > 10 && rowDiff == 1 && (colDiff == 1 || colDiff == -1)) //'typeEnd > 10' moet typeEnd.color == Color::black zijn
				return true;
			return false;
		}
		else if (m_hasMadeMove == false) {
			if (colDiff == 0 && (rowDiff == 2 || rowDiff == 1))
				return true;
			return false;
		}
		else if (colDiff == 0 && rowDiff == 1)
			return true;
		return false;
	}
	else if (m_pawnColor == Color::black) {
		if (typeEnd != -1) {
			if (typeEnd < 10 && rowDiff == -1 && (colDiff == 1 || colDiff == -1)) //'typeEnd > 10' moet typeEnd.color == Color::black zijn
				return true;
			return false;
		}
		else if (m_hasMadeMove == false) {
			if (colDiff == 0 && (rowDiff == -2 || rowDiff == -1))
				return true;
			return false;
		}
		else if (colDiff == 0 && rowDiff == -1)
			return true;
		return false;
	}
	else
		return false;
}