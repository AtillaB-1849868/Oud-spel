#include "Pawn2.h"
#include "Color2.h"
#include <string>

bool Pawn2::checkMove(Type typeEnd, Color colorEnd, int rowStart, int colStart, int rowEnd, int colEnd) const {
	int colDiff = colStart - colEnd;
	int rowDiff = rowStart - rowEnd;
	if (getColor() == Color::white) {
		if (typeEnd != Type::empty) {
			if (colorEnd == Color::black && rowDiff == 1 && (colDiff == 1 || colDiff == -1)) //Dit gaat nog veranderen: 'typeEnd > 10' moet typeEnd.color == Color::black zijn
				return true;
		}
		else if (m_hasMadeMove == false) { //if pawn has not moved yet
			if (colDiff == 0 && (rowDiff == 2 || rowDiff == 1))
				return true;
		}
		else if (colDiff == 0 && rowDiff == 1)
			return true;
	}
	else if (getColor() == Color::black) {
		if (typeEnd != Type::empty) {
			if (colorEnd == Color::white && rowDiff == -1 && (colDiff == 1 || colDiff == -1)) ////Dit gaat nog veranderen: 'typeEnd > 10' moet typeEnd.color == Color::white zijn
				return true;
		}
		else if (m_hasMadeMove == false) { //if pawn has not moved yet
			if (colDiff == 0 && (rowDiff == -2 || rowDiff == -1))
				return true;
		}
		else if (colDiff == 0 && rowDiff == -1)
			return true;
	}
	return false;
}