#ifndef Pawn2_h
#define Pawn2_h

#include "Color2.h"

class Pawn2 {
public:
	Pawn2(int pawnNum, Color pawnColor, bool hasMadeMove) : m_pawnNum{ pawnNum }, m_pawnColor{ pawnColor }, m_hasMadeMove{ hasMadeMove } {};
	int getPawnNum() const { return m_pawnNum; }
	Color getPawnColor() const { return m_pawnColor; }
	bool getHasMadeMove() const { return m_hasMadeMove; }

	bool checkPawnMove(int typeEnd, int rowStart, int colStart, int rowEnd, int colEnd);
private:
	int m_pawnNum;
	Color m_pawnColor;
	bool m_hasMadeMove;
};

#endif