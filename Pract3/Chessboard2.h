
#ifndef Chessboard2_h
#define Chessboard2_h

#include "Pawn2.h"
#include "Color2.h"
#include "Piece.h"
#include <string>

class Chessboard2 {
public:
	Chessboard2();
	void printBoard();
	int checkPieces(Color turn); //checks state of board after turns for victory
	bool setPiece(std::string startPos, std::string endPos, Color turn); //moves pieces on m_board
	bool AISetPiece(); //same as setPiece, but randomly selects piece from ailoclist and randomly moves it
	void updateAILocList(); //updates ai piece coordinate locations
	Type selectPiece(int row, int col); //selects a piece from the m_board
	
private:
	static const int BOARDSIZE = 8;
	Piece* m_board[BOARDSIZE][BOARDSIZE];
	int m_AILocList[BOARDSIZE][2] = { {1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7} };
	const int m_boardWidth{ 41 };
	const int m_numRowCol{ 8 };
	int moves[2] = { 1, 2 };
	int m_numPieces{ 8 };
};

#endif