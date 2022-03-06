#ifndef Chessboard2_h
#define Chessboard2_h

#include "Pawn2.h"
#include "Color2.h"
#include <string>

class Chessboard2 {
public:
	Chessboard2();
	void printBoard();
	bool checkVictory();
	bool setPiece(std::string startPos, std::string endPos, Color turn);
	bool AISetPiece();
	void updateAILocList();

	int selectPiece(int row, int col);
	//bool setPiece(int rowStart, int colStart, int rowEnd, int colEnd, int typeStart);
private:
	static const int BOARDSIZE = 8;
	Pawn2* m_board[BOARDSIZE][BOARDSIZE];

	int m_AILocList[BOARDSIZE][2] = { {1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7} };
	const int m_boardWidth{ 41 };
	const int m_numRowCol{ 8 };
	int moves[2] = { 1, 2 };
	int m_numPieces{ 8 };
};

#endif