#include "Chessboard2.h"
#include "Pawn2.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "Color2.h"
#include <iostream>

Chessboard2::Chessboard2() : m_board
{
	{nullptr, new Knight(Color::black), new Bishop(Color::black), new Queen(Color::black), 
	nullptr, new Bishop(Color::black), new Knight(Color::black), nullptr},
	{new Pawn2(Color::black, false), new Pawn2(Color::black, false), new Pawn2(Color::black, false),
	new Pawn2(Color::black, false), new Pawn2(Color::black, false), new Pawn2(Color::black, false),
	new Pawn2(Color::black, false), new Pawn2(Color::black, false)},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
	{new Pawn2(Color::white, false), new Pawn2(Color::white, false), new Pawn2(Color::white, false),
	new Pawn2(Color::white, false), new Pawn2(Color::white, false), new Pawn2(Color::white, false),
	new Pawn2(Color::white, false), new Pawn2(Color::white, false)},
	{nullptr, new Knight(Color::white), new Bishop(Color::white), new Queen(Color::white),
	nullptr, new Bishop(Color::white), new Knight(Color::white), nullptr},
} {}

/*
* Dit hadden we in m_board gestoken maar voorlopig er uit gelaten omdat er iets fout loopt.

new Knight(Type::knight, Color::black), new Bishop(Type::bishop, Color::black), new Queen(Type::queen, Color::black),
nullptr, new Bishop(Type::bishop, Color::black), new Knight(Type::knight, Color::black),

new Knight(Type::knight, Color::white), new Bishop(Type::bishop, Color::white), new Queen(Type::queen, Color::white),
nullptr, new Bishop(Type::bishop, Color::white), new Knight(Type::knight, Color::white),
*/

void Chessboard2::printBoard() {
	
	std::cout << '\n' << "  ";
	for (int i = 0; i < m_boardWidth; i++)
		std::cout << '-';
	std::cout << '\n';
	for (int k = 0; k < m_numRowCol; k++) {
		std::cout << m_numRowCol - k << " | ";
		for (int l = 0; l < m_numRowCol; l++) {
			Piece* p = m_board[k][l];
			if (m_board[k][l] == nullptr)
				std::cout << "  " << " | ";
			else if (p->getColor() == Color::white) {
				Type t = p->getType();
				if (t == Type::pawn)
					std::cout << "PW" << " | ";
				else if (t == Type::knight)
					std::cout << "NW" << " | ";
				else if (t == Type::bishop)
					std::cout << "BW" << " | ";
				else if (t == Type::queen)
					std::cout << "QW" << " | ";
			}
			else if (p->getColor() == Color::black) {
				Type t = p->getType();
				if (t == Type::pawn)
					std::cout << "PB" << " | ";
				else if (t == Type::knight)
					std::cout << "NB" << " | ";
				else if (t == Type::bishop)
					std::cout << "BB" << " | ";
				else if (t == Type::queen)
					std::cout << "QB" << " | ";
			}
		}
		std::cout << '\n' << "  ";
		for (int j = 0; j < m_boardWidth; j++)
			std::cout << '-';
		std::cout << '\n';
	}
	std::cout << "     ";
	for (int m = 0; m < m_numRowCol; m++) {
		std::cout << (char)('A' + m) << "    ";
	}
	std::cout << "\n";
}

bool Chessboard2::setPiece(std::string startPos, std::string endPos, Color turn) {
	int colStart = startPos[0] - 'A'; //get column from piece as int
	int rowStart = 7 - (startPos[1] - '1'); //get row from piece as int        
	int colEnd = endPos[0] - 'A';
	int rowEnd = 7 - (endPos[1] - '1');
	Type typeStart, typeEnd;
	bool valid = false;
	Piece* start = m_board[rowStart][colStart];
	Piece* end = m_board[rowEnd][colEnd];

	if (rowStart == rowEnd && colStart == colEnd)
		return false;
	typeStart = selectPiece(rowStart, colStart); //get start location
	typeEnd = selectPiece(rowEnd, colEnd); //get end location
	if (typeStart == Type::out || typeEnd == Type::out || typeStart == Type::empty) //if out of border
		return false;
	if (start->getColor() == turn) //if moving piece of valid color						//if type fixed -> getColor == turn + type
	{ 
		
		if (typeEnd == Type::empty)
			valid = m_board[rowStart][colStart]->checkMove(typeEnd, Color::empty, rowStart, colStart, rowEnd, colEnd, m_board);
		else{
			valid = m_board[rowStart][colStart]->checkMove(typeEnd, end->getColor(), rowStart, colStart, rowEnd, colEnd, m_board); //check validity
			if (valid)
				bool pieceTaken = true;
		}
	}
	if (valid) { //if valid: move piece
		if (start->getType() == Type::pawn)
			m_board[rowStart][colStart]->setHasMadeMove(true);
		m_board[rowEnd][colEnd] = m_board[rowStart][colStart];
		m_board[rowStart][colStart] = nullptr;
		if (turn == Color::white)
			return true;
		return true;
	}
	return false;
}




bool Chessboard2::AISetPiece() {
	bool valid = false;
	int rowStart, colStart;
	int randomNum = rand() % 7; //random number for piece coordinates
	rowStart = m_AILocList[randomNum][0];
	colStart = m_AILocList[randomNum][1];
	Type typePiece = selectPiece(rowStart, colStart); //selects piece
	Piece* start = m_board[rowStart][colStart];

	if (start->getColor() == Color::black) { //if piece is Black pawn (moet veranderen in toekomst)
		Type typeEnd = selectPiece(rowStart + 1, colStart);

		if (typeEnd == Type::out) //if off board
			return false;
		Type typeLeftUnder = selectPiece(rowStart + 1, colStart - 1);
		if (typeLeftUnder != Type::out && typeLeftUnder != Type::empty) { //if a piece positioned leftUnder
			valid = m_board[rowStart][colStart]->checkMove(typeLeftUnder, m_board[rowStart+1][colStart-1]->getColor(), rowStart, colStart, rowStart + 1, colStart + 1, m_board); //check if move posible
			if (valid) {
				if (start->getType() == Type::pawn)
					m_board[rowStart][colStart]->setHasMadeMove(true);
				m_board[rowStart + 1][colStart - 1] = m_board[rowStart][colStart];
				m_board[rowStart][colStart] = nullptr;
				return true;
			}
		}
		Type typeRightUnder = selectPiece(rowStart + 1, colStart + 1);
		if (typeRightUnder != Type::out && typeRightUnder != Type::empty) { //if a piece positioned rightUnder
			valid = m_board[rowStart][colStart]->checkMove(typeRightUnder, m_board[rowStart+1][colStart+1]->getColor(), rowStart, colStart, rowStart + 1, colStart - 1, m_board); //check if move posible
			if (valid) {
				if (start->getType() == Type::pawn)
					m_board[rowStart][colStart]->setHasMadeMove(true);
				m_board[rowStart + 1][colStart + 1] = m_board[rowStart][colStart];
				m_board[rowStart][colStart] = nullptr;
				return true;
			}
		}
		if (m_board[rowStart][colStart]->getHasMadeMove() == false && m_board[rowStart][colStart]->getType() == Type::pawn) { //if the pawn has not moved yet
			int randomMoveNum = rand() % 2;
			int move = moves[randomMoveNum]; //select one of 2 moves
			typeEnd = selectPiece(rowStart, colStart + move);
			valid = m_board[rowStart][colStart]->checkMove(typeEnd, m_board[rowStart+move][colStart]->getColor(), rowStart, colStart, rowStart + move, colStart, m_board); //check if move posible
			if (valid) {
				m_board[rowStart][colStart]->setHasMadeMove(true);
				m_board[rowStart + move][colStart] = m_board[rowStart][colStart];
				m_board[rowStart][colStart] = nullptr;
				return true;
			}
		}

		valid = m_board[rowStart][colStart]->checkMove(typeEnd, m_board[rowStart+1][colStart]->getColor(), rowStart, colStart, rowStart + 1, colStart, m_board); //otherwise just move one down
		if (valid) {
			m_board[rowStart][colStart]->setHasMadeMove(true);
			m_board[rowStart + 1][colStart] = m_board[rowStart][colStart];
			m_board[rowStart][colStart] = nullptr;
			return true;
		}
		else
			return false;
	}
	return false;
}

void Chessboard2::updateAILocList() {
	int z = 0;
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			Type type = selectPiece(i, j);
			if (type != Type::empty) {
				if (m_board[i][j]->getColor() == Color::black) {
					m_AILocList[z][0] = i;
					m_AILocList[z][1] = j;
					++z;
				}
			}
			if (i == BOARDSIZE - 1 && j == BOARDSIZE - 1) { //if it has gone through the whole board
				m_numPieces -= 1; //one piece has been taken
				m_AILocList[z][0] = -1;
				m_AILocList[z][1] = -1;
			}
			if (z == m_numPieces)
				return;
		}
	}
}

Type Chessboard2::selectPiece(int row, int col) {
	Piece* p = m_board[row][col];
	if (col >= BOARDSIZE && row >= BOARDSIZE && col < 0 && row < 0) // if out of range
		return Type::out;
	else if (p == nullptr) //if empty space
		return Type::empty;
	else
		return p->getType(); //take piece
}

int Chessboard2::checkPieces(Color turn) {
	int z = 0;
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			Type type = selectPiece(i, j);
			if (type != Type::empty) {
				if (m_board[i][j]->getColor() != turn) {
					++z;
				}
			}
		}
	}
	return z;
}


